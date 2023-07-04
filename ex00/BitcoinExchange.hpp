#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <cstring>
# include <sstream>
# include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> data;
	bool		checkDate(const std::string &date);
	bool		checkValue(const std::string &str);
	std::string	findDate(const std::string &date);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange& operator=(const BitcoinExchange &src);

	void	run(char *filename);
	float	findValue(std::string &date);
	void	print_map(void);

	class ErrorException: public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif