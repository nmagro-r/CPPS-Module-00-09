/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:10:15 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/26 16:52:32 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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
    
};


#endif