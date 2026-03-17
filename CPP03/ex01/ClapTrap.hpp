/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:19:15 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/04 18:22:52 by nmagro-r         ###   ########.fr       */
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
        int getAttackDamage(); //permite preguntar cuanto daño causa
        
        protected: // permite que otras subclases accedan directamente a: name,hP,eP,aD.
            std::string name;
            int hitPoints;
            int energyPoints;
            int attackDamage;
};



#endif