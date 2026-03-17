/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:06:09 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 12:09:52 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Animal constructor" << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << "String constructor called " << type << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &copy)
{
    this->type = copy.type;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->type = copy.type;
    return(*this);
}

void Animal::makeSound() const
{
    std::cout << "No animal, so no sound paying... " << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType()const
{
    return(this->type);
}