#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenum;
		std::string	secret;
		void 		printByFormat(std::string str);
	public:
		void		enterContact();
		void		printContact();
};

#endif