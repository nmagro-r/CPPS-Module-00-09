/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:07:55 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/26 14:49:31 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:

        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        int getHp();
        int getEnergy();
        std::string getName();
        int getAttackDamage();
        
        protected:
            std::string name;
            int hitPoints;
            int energyPoints;
            int attackDamage;
};



#endif