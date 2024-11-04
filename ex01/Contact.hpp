/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:28:29 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/11/04 16:14:58 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:

	Contact(void);
	~Contact(void);

	void	setInfo(const std::string &firstName,
					const std::string &lastName,
					const std::string &nickName,
					const std::string &phoneNumber,
					const std::string &darkestSecret);

	void	showDetails(int index) const;
	void	getInfo() const;
};

#endif
