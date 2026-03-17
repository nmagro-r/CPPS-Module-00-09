/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:31:12 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/20 15:10:34 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " has spawned " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    name = copy.name;
    hitPoints = copy.hitPoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "asign operator called" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return(*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor" << std::endl;
}
void ClapTrap ::attack(const std::string &target)
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
    std::cout << "ClapTrap " << name << " has attacked " << target <<  " causing " << attackDamage << " point of damage " << std::endl;
    energyPoints--;
}
    
void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints = hitPoints - amount;
    if(hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " has taken " << amount << " hp of damage " << std::endl;
    if(hitPoints <= 0)
    {
        std::cout << "has no hp left" << std::endl;
        return;
    }
}

 void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0)
    {
        std::cout << "No energy points available" << std::endl;
        return;
    }
    if (hitPoints <= 0)
    {
        std::cout << "No hp available" << std::endl;
        return;
    }
    else
    {
        hitPoints = hitPoints + amount;
    }
    
    std::cout << "ClapTrap" << name << " repairs itself " << amount << " hit points " << std::endl;
    energyPoints--;
        
}

int ClapTrap::getHp()
{
    return(hitPoints);
}
int ClapTrap::getEnergy()
{
    return(energyPoints);
}

std::string ClapTrap::getName()
{
    return(name);
}

int ClapTrap::getAttackDamage()
{
    return(attackDamage);
}