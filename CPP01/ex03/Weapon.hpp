/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:17:25 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/27 16:24:14 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP


#include <string>
#include <iostream>


class Weapon
{
    public:
        Weapon(const std::string &type);
        ~Weapon();
        const std::string &getType() const;
        void setType(const std::string &newType);


    private: 
        std::string type;
};



#endif
