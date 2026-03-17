/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:23:25 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/01 18:30:05 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name"), FragTrap(), ScavTrap(), name("DiamondTrap")
{
    this->hitPoints = 100;        // Valores de FragTrap
    this->energyPoints = 50;      // Valores de ScavTrap
    this->attackDamage = 30;      // Valores de FragTrap

    std::cout << "Diamond " << name << " has been constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)
{
    this->hitPoints = 100;        // Valores de FragTrap
    this->energyPoints = 50;      // Valores de ScavTrap
    this->attackDamage = 30;      // Valores de FragTrap

    std::cout << "Diamond " << name << " has been constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), name(copy.name)
{
    std::cout << "DiamondTrap " << name << " arrives" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    this->attackDamage = copy.attackDamage;
    this->energyPoints = copy.energyPoints;
    this->hitPoints = copy.hitPoints;
    this->name = copy.name;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " has been destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << ", they call me " << ClapTrap::name << std::endl;
}
