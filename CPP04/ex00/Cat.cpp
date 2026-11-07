/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:06:29 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 12:09:42 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default cat constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->type = copy.type;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow " << std::endl;
}

Cat::~Cat()
{
    std::cout << "Calling cat destructor" << std::endl;
}