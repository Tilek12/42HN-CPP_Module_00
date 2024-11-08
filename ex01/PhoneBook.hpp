/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:28:26 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/08 13:57:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {

private:

	Contact	_contacts[8];
	int		_currentContactIndex;
	int		_totalContacts;

public:

	PhoneBook(void);

	bool	isDigit(const std::string &str) const;
	bool	isAlphabetic(const std::string &str) const;
	bool	isValidInput(const std::string &firstName,
						const std::string &lastName,
						const std::string &nickName,
						const std::string &phoneNumber,
						const std::string &darkestSecret);
	bool	getInput(const std::string &promt, std::string &input);
	void	incorrectInputHandler(void) const;
	void	addContact(void);
	void	searchContact(void) const;

};

#endif
