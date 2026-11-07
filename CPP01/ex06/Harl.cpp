/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:48:27 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/30 16:49:04 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << " [Debug]" << std::endl << " Just checking Harl is OK." << std::endl;
}

void Harl::info(void)
{
    std::cout << "[info]" << std::endl << "My name is Harl, i just complain." << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[warning]" << std::endl << "A simple message to remind you to avoid talking to Harl" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[Error]" << std::endl << "Harl has crashed, please try again later... or not." << std::endl;
}


void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = -1;
    
    Harl action;
    while (++i < 4)
    {
        if (level == levels[i])
        {
            break;
        }
    }
    switch (i)
    {
    case 0:
        this->debug();
        // fall through
    case 1:
        this->info();
        // fall through
    case 2:
        this->warning();
        // fall through
    case 3:
        this->error();
        break;
    default:
        std::cout << "Choose a correct option for a complain" << std::endl;
        break;
    }
}