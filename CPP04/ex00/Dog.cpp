/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:06:58 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 12:09:27 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Calling default Dog constructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->type = copy.type;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    this->type = copy.type;
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}