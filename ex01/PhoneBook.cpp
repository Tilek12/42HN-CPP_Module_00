/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:22:39 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/18 11:50:37 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

PhoneBook::PhoneBook(void) : _currentContactIndex(0), _totalContacts(0) {}

bool	PhoneBook::isDigit(const std::string &str) const {

	if (str.empty()) return false;

	if (str[0] == '+') {
		for (size_t i = 1; i < str.size(); i++) {
			if (!std::isdigit(str[i])) return false;
		}
	} else {
		for (char c : str) {
			if (!std::isdigit(c)) return false;
		}
	}

	return true;

}

bool	PhoneBook::isAlphabetic(const std::string &str) const {

	for (char c : str) {
		if (!std::isalpha(c)) return false;
	}

	return true;

}

bool	PhoneBook::isValidInput(const std::string &firstName,
								const std::string &lastName,
								const std::string &nickName,
								const std::string &phoneNumber,
								const std::string &darkestSecret) {
	bool	noError = true;

	if (firstName.empty()
		|| lastName.empty()
		|| nickName.empty()
		|| phoneNumber.empty()
		|| darkestSecret.empty()) {
		std::cout << B_RED << "ERROR: Contact can't have empty fields!\n" << RESET;
		noError = false;
	}

	if (!isAlphabetic(firstName)) {
		std::cout << B_RED << "ERROR: First Name must include only alphabetic characters!\n" << RESET;
		noError = false;
	}

	if (!isAlphabetic(lastName)) {
		std::cout << B_RED << "ERROR: Last Name must include only alphabetic characters!\n" << RESET;
		noError = false;
	}

	if (!isDigit(phoneNumber)) {
		std::cout << B_RED << "ERROR: Phone Number must include only digits ('+' symbol is possible)!\n" << RESET;
		noError = false;
	}

	std::cout << std::endl;

	return noError;

}

void	PhoneBook::incorrectInputHandler(void) const {

	if (std::cin.eof()) {
		std::cout << B_RED << "\nEOF signal detected. Returning to main menu.\n" << RESET << std::endl;
	} else {
		std::cout << B_RED << "ERROR: Invalid input.\n" << RESET << std::endl;
	}

	std::cin.clear();

}

bool	PhoneBook::getInput(const std::string &promt, std::string &input) {

	std::cout << B_YELLOW << promt << RESET;

	if (!std::getline(std::cin, input)) {
		incorrectInputHandler();
		return false;
	}

	return true;

}

void	PhoneBook::addContact(void) {

	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	if (!getInput("Enter First Name: ", firstName)
		|| !getInput("Enter Last Name: ", lastName)
		|| !getInput("Enter Nickname: ", nickName)
		|| !getInput("Enter Phone Number: ", phoneNumber)
		|| !getInput("Enter Darkest Secret: ", darkestSecret)) {
		return;
	}

	if (!isValidInput(firstName, lastName, nickName, phoneNumber, darkestSecret)) {
		return;
	}

	std::cout << std::endl;
	_contacts[_currentContactIndex].setInfo(firstName, lastName, nickName, phoneNumber, darkestSecret);
	_currentContactIndex = (_currentContactIndex + 1) % 8;

	if (_totalContacts < 8) _totalContacts++;

}

void	PhoneBook::searchContact(void) const {

	std::string	input;
	int			index;

	std::cout << YELLOW << std::setw(10) << "Index" << "|" << RESET;
	std::cout << YELLOW << std::setw(10) << "First Name" << "|" << RESET;
	std::cout << YELLOW << std::setw(10) << "Last Name" << "|" << RESET;
	std::cout << YELLOW << std::setw(10) << "Nickname" << RESET << std::endl;

	for (int i = 0; i < _totalContacts; i++) {
		_contacts[i].showDetails(i);
	}

	std::cout << B_GREEN << "\nTo view Details enter index: " << RESET;

	if (!std::getline(std::cin, input)) {
		incorrectInputHandler();
		return;
	}

	if (input.empty() || !isDigit(input)) {
		std::cout << B_RED << "ERROR: Incorrect input.\n" << RESET << std::endl;
		return;
	}

	index = std::stoi(input);

	if (index < 0 || index >= _totalContacts) {
		std::cout << B_RED << "ERROR: Incorrect index.\n" << RESET << std::endl;
	} else {
		std::cout << std::endl;
		_contacts[index].getInfo();
	}

}
