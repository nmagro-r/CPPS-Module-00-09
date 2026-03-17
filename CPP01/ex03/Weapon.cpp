/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:17:11 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/27 16:25:36 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{   
}
Weapon::~Weapon()
{
}

const std::string &Weapon::getType()const
{
    return(type);
}

void Weapon::setType(const std::string &newType)
{
    type = newType;
}