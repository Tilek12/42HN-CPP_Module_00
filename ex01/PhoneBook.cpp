/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:22:39 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/05 17:17:30 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : currentContactIndex(0), totalContacts(0) {}

void	PhoneBook::addContact(void) {

	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << B_YELLOW << "Enter First Name: " << RESET;
	if (!std::getline(std::cin, firstName)) {
		if (std::cin.eof()) {
			std::cout << B_RED << "\nEnd of input detected." << RESET << std::endl;
			std::cin.clear();
			return ;
		}
	}
	std::cout << B_YELLOW << "Enter Last Name: " << RESET;
	if (!std::getline(std::cin, lastName)) return ;
	std::cout << B_YELLOW << "Enter Nickname: " << RESET;
	if (!std::getline(std::cin, nickName)) return ;
	std::cout << B_YELLOW << "Enter Phone Number: " << RESET;
	if (!std::getline(std::cin, phoneNumber)) return ;
	std::cout << B_YELLOW << "Enter Darkest Secret: " << RESET;
	if (!std::getline(std::cin, darkestSecret)) return ;

	if (firstName.empty()
		|| lastName.empty()
		|| nickName.empty()
		|| phoneNumber.empty()
		|| darkestSecret.empty()) {
		std::cout << B_RED << "ERROR!" << std::endl;
		std::cout << "Contact can't have empty fields!" << RESET << std::endl;
		std::cout << std::endl;
		return ;
	}

	std::cout << std::endl;
	contacts[currentContactIndex].setInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);
	currentContactIndex = (currentContactIndex + 1) % 8;
	if (totalContacts < 8) totalContacts++;
}

void	PhoneBook::searchContact(void) const {

	int	index;

	std::cout << YELLOW << std::setw(10) << "Index" << "|" << RESET;
	std::cout << YELLOW << std::setw(10) << "First Name" << "|" << RESET;
	std::cout << YELLOW << std::setw(10) << "Last Name" << "|" << RESET;
	std::cout << YELLOW << std::setw(10) << "Nickname" << RESET << std::endl;

	for (int i = 0; i < totalContacts; i++) {
		contacts[i].showDetails(i);
	}

	std::cout << std::endl;
	std::cout << B_BLUE << "To view Info enter index: " << RESET;
	if (!(std::cin >> index) || index < 0 || index >= totalContacts) {
		std::cout << B_RED << "ERROR!" << RESET << std::endl;
		std::cout << B_RED << "Incorrect index!" << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} else {
		std::cout << std::endl;
		contacts[index].getInfo();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
