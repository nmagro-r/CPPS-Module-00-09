/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:55:48 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/20 16:08:19 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

void Contact::setName(const std::string &name)
{
	first_name = name;
}

void Contact::setLast(const std::string &last)
{
	last_name = last;
}

void Contact::setNick(const std::string &nick)
{
	nickname = nick;
}

void Contact::setPhone(const std::string &phone)
{
	phone_number = phone;
}

void Contact::setSecret(const std::string &secret)
{
	darkest_secret = secret;
}

std::string Contact::getName() const
{
	return(first_name);
}

std::string Contact::getLast() const
{
	return(last_name);
}

std::string Contact::getNick() const
{
	return(nickname);
}

std::string Contact::getPhone() const
{
	return(phone_number);
}

std::string Contact::getSecret() const
{
	return(darkest_secret);
}