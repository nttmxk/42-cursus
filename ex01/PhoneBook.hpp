#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {
	private:
		Contact contact[8];
		int		len;
		int 	last;
		void 	printContact(int i);
		void 	printBook();
	public:
		PhoneBook();
		void	searchContact();
		void 	addContact();
};

#endif
