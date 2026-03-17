/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:30:06 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/20 15:12:17 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
	ClapTrap roland = ClapTrap("Roland");
	ScavTrap jack = ScavTrap("Jack");
	FragTrap lilith = FragTrap("Lilith");

	jack.attack("Roland");
    roland.takeDamage(jack.getAttackDamage());
	jack.guardGate();
	
	lilith.attack("Roland");
	roland.takeDamage(lilith.getAttackDamage());
    lilith.highFivesGuys();

	return (0);	
}