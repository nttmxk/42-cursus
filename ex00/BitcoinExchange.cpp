#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){ *this = src; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
		data = src.data;
	return (*this);
}

/*
 * 문제상황
 * 1. YYYY-MM-DD 형식오류
 * 	1.1. 숫자자리에 문자
 * 	1.2. '-' 위치
 * 2. 숫자 범위오류
 *  2.1. 범위 미만초과
 *  2.2. 달마다 31일
 *  2.3. 2월 특수케이스
 */
bool BitcoinExchange::checkDate(const std::string &date)
{
	if (date.length() != 10)
		return false;

	for (int i = 0; i < 10; ++i) {
		if (i != 4 && i != 7) {
			if (!std::isdigit(date[i]))
				return false;
		}
		else {
			if (date[i] != '-')
				return false;
		}
	}

	int y, m, d;

	std::stringstream(date.substr(0, 4)) >> y;
	std::stringstream(date.substr(5, 2)) >> m;
	std::stringstream(date.substr(8, 2)) >> d;

	if (m == 0 || d == 0 || m > 12 || d > 31)
		return false;
	if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
			if (d > 29)
				return false;
		}
		else if (d > 28)
			return false;
	}
	return true;
}

/*
 * 문제상황
 * 1. 문자포함
 * 	1.1. 첫자리부터 오류
 * 	1.2. 마지막자리 오류
 * 2. 범위초과
 */
bool BitcoinExchange::checkValue(const std::string &str, bool Input)
{
	char *ptr = NULL;
	double val;

	val = std::strtod(str.c_str(), &ptr);

	if (val == 0.0 && !std::isdigit(str[0]))
		return false;
	if (*ptr && std::strcmp(ptr, "f"))
		return false;
	if (val < 0)
		return false;
	if (Input && val > 1000)
		return false;
	return true;
}

void BitcoinExchange::run(char *filename)
{
	getRate();
	handleInput(filename);
}

void BitcoinExchange::getRate(void)
{
	std::ifstream	csv("./data.csv");

	if (csv.fail())
		throw ErrorException();

	std::string	line;
	float 		val;

	if (!std::getline(csv, line))
		throw ErrorException();
	if (std::strcmp(line.c_str(), "date,exchange_rate"))
		throw ErrorException();

	while (std::getline(csv, line))
	{
		if (line.length() < 12 || line[10] != ',')
			throw ErrorException();
		if (!checkDate(line.substr(0, 10)))
			throw ErrorException();
		if (!checkValue(line.substr(11), false))
			throw ErrorException();
		std::stringstream(line.substr(11)) >> val;
		data[line.substr(0, 10)] = val;
	}
	csv.close();
	if (data.empty())
		throw ErrorException();
}

void BitcoinExchange::handleInput(char *filename)
{
	std::ifstream	input(filename);

	if (input.fail())
		throw ErrorException();

	std::string line;

	if (!std::getline(input, line))
		throw ErrorException();
	if (std::strcmp(line.c_str(), "date | value"))
		throw ErrorException();

	while (std::getline(input, line))
	{
		if (line.length() < 14 || line[11] != '|' || line[10] != ' ' || line[12] != ' ')
			throw ErrorException();
		if (!checkDate(line.substr(0, 10)))
			throw ErrorException();
		if (!checkValue(line.substr(13), true))
			throw ErrorException();
		printResult(line);
	}
	input.close();
}

void BitcoinExchange::printResult(std::string &line)
{
	std::string date;
	float val;
	float result;

	date = line.substr(0, 10);
	std::stringstream(line.substr(13)) >> val;
	result = val * findValue(findDate(date)); // what if result has invalid value

	std::cout << date << " => " << val << " = " << result << '\n';
}

std::string BitcoinExchange::findDate(const std::string &date)
{
	std::map<std::string, float>::const_iterator it;

	it = data.find(date);
	if (it != data.end())
		return it->first;
	it = data.lower_bound(date);
	if (it == data.begin())
		throw ErrorException();
	return (--it)->first;
}

float BitcoinExchange::findValue(const std::string &date)
{
	return data[date];
}

const char* BitcoinExchange::ErrorException::what(void) const throw()
{
	return "Error\n";
}

void BitcoinExchange::print_map(void)
{
	for (std::map<std::string, float>::iterator it = data.begin(); it != data.end() ; ++it) {
		std::cout << it->first << " " << it->second << '\n';
	}
}
