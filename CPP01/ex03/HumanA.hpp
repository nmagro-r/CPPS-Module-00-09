/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:18:09 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/27 16:23:32 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();

        void attack(void);



    private: 
        std::string name;
        Weapon &weapon;



    
};


#endif