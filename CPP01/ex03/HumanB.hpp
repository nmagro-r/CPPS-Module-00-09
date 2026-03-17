/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:18:44 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/27 16:24:01 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public: 
        HumanB(std::string name);
        ~HumanB();



    void setWeapon(Weapon &newWeapon);
    void attack();


    private: 
        Weapon *weapon_1;
        std::string name;
        

};


#endif