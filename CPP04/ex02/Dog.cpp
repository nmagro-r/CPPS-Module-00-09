/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:49:26 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 17:49:42 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor" << std::endl;
    brain = new Brain(*copy.brain); // uso real del campo
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog operator=" << std::endl;

    if (this != &copy)
    {
        Animal::operator=(copy);

        // deep copy
        *brain = *copy.brain; // uso real del campo
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
    delete brain; // uso real del campo
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}
