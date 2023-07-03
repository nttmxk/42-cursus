#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <cstring>
# include <map>

class BitcoinExchange{
private:
	std::map<std::string, float> data;
	bool checkDate(std::string &date);
	bool checkValue(std::string &str);
	std::string findDate(std::string &date);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange& operator=(const BitcoinExchange &src);

	run(char *filename);
	float findValue(std::string &date);

	class ErrorException: public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif