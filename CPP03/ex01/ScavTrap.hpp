/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:19:54 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/24 15:20:44 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //scavTrap hereda publicamente de clapTrap
{
    public: 
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
        ~ScavTrap();

        
        void attack(const std::string &target);
        void guardGate();

    private: 
        //reutilizamos los protected
    
};

#endif