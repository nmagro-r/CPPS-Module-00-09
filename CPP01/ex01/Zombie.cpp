/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:19:58 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/27 15:20:10 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    
}
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
