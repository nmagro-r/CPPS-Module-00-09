/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:18:51 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/18 14:24:20 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    ClapTrap Joe = ClapTrap();
    ScavTrap Test = ScavTrap("testing");
    
	Test.attack("Roland");
	Joe.takeDamage(Test.getAttackDamage());
	Joe.beRepaired(10);
	Test.guardGate();
    return(0);
}