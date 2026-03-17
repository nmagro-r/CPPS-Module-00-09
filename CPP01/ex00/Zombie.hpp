/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:52:54 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/30 15:55:33 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public: 
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);
        void setName(std::string newName);
        


    private: 
        std::string name;
};

    Zombie *newZombie(std::string name); //asignacion heap
    void randomChump(std::string name); //asignacion stack

#endif