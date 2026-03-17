/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:05:36 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/26 14:49:43 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap roland = ClapTrap("Roland");
	ScavTrap jack = ScavTrap("Jack");
	FragTrap lilith = FragTrap("Lilith");
	DiamondTrap krieg =  DiamondTrap("Krieg");

	std::cout << "\nClaptrap HP " << roland.getHp() << " EP " << roland.getEnergy() << " AD " << roland.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "ScavTrap HP " << jack.getHp() << " EP " << jack.getEnergy() << " AD " << jack.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "Fragtrap HP " << lilith.getHp() << " EP " << lilith.getEnergy() << " AD " << lilith.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "Diamond HP " << krieg.getHp() << " EP " << krieg.getEnergy() << " AD " << krieg.getAttackDamage() << std::endl;
	std::cout << std::endl;

	jack.attack("Roland");
    roland.takeDamage(jack.getAttackDamage());
	jack.guardGate();
    
	lilith.attack("Roland");
	roland.takeDamage(lilith.getAttackDamage());
    lilith.highFivesGuys();
	
	krieg.attack("Roland");
	roland.takeDamage(krieg.getAttackDamage());
    krieg.whoAmI();
	return (0);
}