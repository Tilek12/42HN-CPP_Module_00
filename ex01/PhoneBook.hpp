/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:28:26 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/05 11:16:48 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {

private:
	Contact contacts[8];
	int	currentContactIndex;
	int	totalContacts;

public:
	PhoneBook(void);
	void	addContact(void);
	void	searchContact(void) const;
};

#endif
