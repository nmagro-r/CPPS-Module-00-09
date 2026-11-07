/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:28:11 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 12:08:38 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Default cat constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    brain = new Brain(*copy.brain);
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
        delete brain;
        brain = new Brain(*copy.brain);
    }
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow " << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Calling cat destructor" << std::endl;
}