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
	std::map<std::string, float>	data;
	bool		checkDate(const std::string &date);
	bool		checkValue(const std::string &str, bool Input);
	std::string	findDate(const std::string &date);
	float		findValue(const std::string &date);
	void		printResult(const std::string &line);
	void		getRate(void);
	void		handleInput(const char *filename);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange& operator=(const BitcoinExchange &src);

	void	run(const char *filename);
	void	print_map(void);
};

#endif