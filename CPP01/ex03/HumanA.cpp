/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:17:50 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/29 17:57:00 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name_param, Weapon &weapon_param): name(name_param), weapon(weapon_param)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weapon.getType() <<  std::endl;
}