/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:55:16 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/22 14:50:04 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : total_contacts(0), oldest_contact(0) {}
PhoneBook::~PhoneBook()
{
}
void PhoneBook::add()
{
	Contact new_contact;

	std::string input;
	std::cout << "Insert new name: \n";
	std::getline(std::cin, input);
	new_contact.setName(input);
	if(input.empty())
	{
		std::cout << "All fields should be filled, returning to menu: " << std::endl;
		return;
	}

	std::cout << "Insert new last name: \n";
	std::getline(std::cin, input);
	new_contact.setLast(input);
	if(input.empty())
	{
		std::cout << "All fields should be filled, returning to menu: " << std::endl;
		return;
	}

	std::cout << "Insert nickname: \n";
	std::getline(std::cin, input);
	new_contact.setNick(input);
	if(input.empty())
	{
		std::cout << "All fields should be filled, returning to menu: " << std::endl;
		return;
	}

	std::cout << "Insert phone number: \n";
	std::getline(std::cin, input);
	new_contact.setPhone(input);
	if(input.empty())
	{
		std::cout << "All fields should be filled, returning to menu: " << std::endl;
		return;
	}

	std::cout << "Insert your darkest secret: \n";
	std::getline(std::cin, input);
	new_contact.setSecret(input);
	
	int pos;

	if(total_contacts < 8)
	{
		pos = total_contacts;
		total_contacts++;
	}
	else
	{
		pos = oldest_contact;
		oldest_contact = (oldest_contact + 1) % 8;
	}
	contacts[pos] = new_contact;
}

void PhoneBook::search()
{
	std::string input;
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nick Name" << std::endl;
	
	for(int i = 0; i < total_contacts; i++)
	{
		std::string name = contacts[i].getName();
		if(name.length() > 10)
			name = name.substr(0,9) + ".";
		std::string last = contacts[i].getLast();
		if(last.length() > 10)
			last = last.substr(0,9) + ".";
		std::string nick = contacts[i].getNick();
		if(nick.length() > 10)
			nick = nick.substr(0,9) + ".";
		
		std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << name << "|"
                  << std::setw(10) << last << "|"
                  << std::setw(10) << nick << std::endl;
	}

	int index = -1;
	std::cout << "Select an index\n";
	std::getline(std::cin, input);
	index = std::atoi(input.c_str()) -1;

	if (index < 0 || index >= total_contacts)
    {
        std::cout << "invalid index. \n";
        return;
    }
    std::cout << "First name: " << contacts[index].getName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLast() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNick() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhone() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
    std::cout << std::endl;
}

