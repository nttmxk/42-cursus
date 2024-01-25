/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:42:49 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/15 14:42:50 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
