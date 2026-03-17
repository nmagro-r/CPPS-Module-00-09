/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:18:28 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/29 17:43:16 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon_1 = NULL;
}
HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon_1 = &newWeapon;
}

void HumanB::attack()
{
    if(weapon_1)
        std::cout << name << " attacks with their " << weapon_1->getType() << std::endl;
    else 
        std::cout << name << " has no weapon " << std::endl;
}