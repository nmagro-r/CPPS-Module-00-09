/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:07:53 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/30 19:49:13 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Default cat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    this->type = copy.type;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    this->type = copy.type;
    return(*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow " << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Calling cat destructor" << std::endl;
}