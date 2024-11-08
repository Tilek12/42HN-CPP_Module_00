/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:22:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/08 13:56:14 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void	Contact::setInfo(const std::string &firstName,
						const std::string &lastName,
						const std::string &nickName,
						const std::string &phoneNumber,
						const std::string &darkestSecret) {

	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;

}

void	Contact::getInfo() const {

	std::cout << YELLOW << "First name:	" << RESET << _firstName << std::endl;
	std::cout << YELLOW << "Last name:	" << RESET << _lastName << std::endl;
	std::cout << YELLOW << "Nickname:	" << RESET << _nickName << std::endl;
	std::cout << YELLOW << "Phone number:	" << RESET << _phoneNumber << std::endl;
	std::cout << YELLOW << "Darkest secret:	" << RESET << _darkestSecret << std::endl;
	std::cout << std::endl;

}

void	Contact::showDetails(int index) const {

	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|";
	std::cout << std::setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|";
	std::cout << std::setw(10) << (_nickName.length() > 10 ? _nickName.substr(0, 9) + "." : _nickName) << std::endl;

}
