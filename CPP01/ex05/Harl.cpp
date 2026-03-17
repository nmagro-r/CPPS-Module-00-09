/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:28:19 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/30 15:35:13 by nmagro-r         ###   ########.fr       */
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
    void (Harl::*lvlPtr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    
    Harl action;
    while (i < 4)
    {
        if (level == levels[i])
        {
            (this->*lvlPtr[i])();  //ejecutar accion en el objeto action.
            break;
        }
        i++;
    }
}