/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:35:36 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/05 17:52:39 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {

	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << B_CYAN << "Enter command (ADD, SEARCH, EXIT): " << RESET;
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cout << B_RED << "\nEnd of input detected. Exiting." << RESET << std::endl;
				break ;
			}
			std::cin.clear();
			std::cout << B_RED << "ERROR!" << RESET << std::endl;
			std::cout << B_RED << "Input failed!" << RESET << std::endl;
		}
		if (command == "ADD") {
			std::cout << std::endl;
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			std::cout << std::endl;
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break ;
		} else {
			std::cout << B_RED << "ERROR!" << RESET << std::endl;
			std::cout << B_RED << "Incorrect command!" << RESET << std::endl;
			std::cout << B_RED << "Use ADD, SEARCH or EXIT commands only!" << RESET << std::endl;
			std::cout << std::endl;
		}
	}

	return 0;
}
