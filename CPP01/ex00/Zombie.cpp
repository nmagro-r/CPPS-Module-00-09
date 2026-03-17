/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:50:17 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/22 16:08:11 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(std::string zombieName)
{
    name = zombieName;
    std::cout << name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName)
{
    name = newName;
}