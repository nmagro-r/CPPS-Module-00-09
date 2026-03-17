/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:23:24 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/18 14:06:51 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap Joe = ClapTrap();
    ClapTrap Test = ClapTrap("testing");
    
    Joe.attack("Test");
    Test.takeDamage(2);
    Test.beRepaired(1);
    Test.attack("Joe");
    Test.takeDamage(5);
    return(0);
}