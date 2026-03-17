/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:55:35 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/22 15:49:07 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string line;

    while (true)
    {
        std::cout  << "Type ADD, SEARCH or EXIT: " << std::endl;
        std::getline(std::cin, line);
        
        if(std::cin.eof())
            exit (1);
        if (line.compare("ADD") == 0)
            phoneBook.add();
        else if (line.compare("SEARCH") == 0)
            phoneBook.search();
        else if (line.compare("EXIT") == 0)
        {
            std::cout << "closing program ..." << std::endl;
            break;   
        }
    }
    return(0);
}
