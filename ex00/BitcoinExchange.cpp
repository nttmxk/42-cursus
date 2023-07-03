#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){ *this = orig; }
BitcoinExchange::BitcoinExchange& operator=(const BitcoinExchange &src) {
	if (this != src)
		this->data = orig.data;
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
bool BitcoinExchange::checkDate(std::string &date)
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
bool BitcoinExchange::checkValue(std::string &str)
{
	char *ptr = NULL;
	double val;

	val = std::strtod(str.c_str(), &ptr);

	if (val == 0.0 && !std::isdigit(str[0]))
		return false;
	if (*ptr && std::strcmp(ptr, "f"))
		return false;
	if (val < 0 || val > 1000)
		return false;
	return true;
}

BitcoinExchange::run(char *filename)
{
	std::ifstream	csv("./data.csv");

	if (file.fail())
		throw ErrorException();

	std::string	line;
	size_t		deli;
	float 		val;

	if (!std::getline(csv, line))
		throw ErrorException();
	if (std::strcmp(line, "date,exchange_rate"))
		throw ErrorException();

	while (std::getline(csv, line))
	{
		deli = line.find(',');
		if (checkDate(line.substr(0, deli)) == false)
			throw ErrorException();
		if (checkValue(line.substr(deli)) == false)
			throw ErrorException();

		std::stringstream(line.substr(deli)) >> val;
		data[line.substr(0, deli)] = val;
	}
	csv.close();
	if (data.empty())
		throw ErrorException();
}

std::string BitcoinExchange::findDate(std::string &date)
{

}

float BitcoinExchange::findValue(std::string &date)
{

}


const char* BitcoinExchange::ErrorException::what(void) const throw()
{
	return "Error\n";
}
