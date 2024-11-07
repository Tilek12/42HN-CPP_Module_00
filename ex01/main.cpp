/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:35:36 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/07 21:07:46 by tkubanyc         ###   ########.fr       */
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
				std::cin.clear();
				std::cout << B_RED << "\nEOF signal detected. Exiting.\n" << RESET << std::endl;
				break;
			}
			std::cin.clear();
			std::cout << B_RED << "ERROR: Input failed!\n" << RESET << std::endl;
			continue;
		}

		if (command == "ADD") {
			std::cout << std::endl;
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			std::cout << std::endl;
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << B_RED << "ERROR: Incorrect command!" << std::endl;
			std::cout << "Use ADD, SEARCH or EXIT commands only!\n" << RESET << std::endl;
		}
	}

	return 0;
}
