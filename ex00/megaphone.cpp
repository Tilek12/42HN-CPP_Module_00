/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:17:23 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/03 19:12:28 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printUppercase(char *str) {

	for (int i = 0; str[i]; i++) {
		std::cout << static_cast<char>(std::toupper(str[i]));
	}
}

int	main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			printUppercase(argv[i]);
			if (i < argc - 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
