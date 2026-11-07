/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:20:06 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/18 14:25:05 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " arrives!" << std::endl;
}

// ScavTrap::ScavTrap()
// {
//     std::cout << "default constructor in Scavtrap" << std::endl;
// }

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " arrives!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "Copy constructor called in Scavtrap" << std::endl;
    name = copy.name;
    hitPoints = copy.hitPoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "asign operator called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return(*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints <= 0)
    {
        std::cout << "No energy points available" << std::endl;
        return;
    }
    if (hitPoints <= 0)
    {
        if (hitPoints < 0)
            hitPoints = 0;
        std::cout << "No hp available" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " has attacked " << target <<  " causing " << attackDamage << " point of damage " << std::endl;
    energyPoints--;
}