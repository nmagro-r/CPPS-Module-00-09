/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:35:06 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/09 13:11:24 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main()
{
    std::cout << "\n--- Creating Animals ---\n";
    Animal* animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Making Sounds ---\n";
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deep Copy Test ---\n";
    Dog original;
    original.getBrain()->setIdea(0, "Eat");

    Dog copy = original;  // deep copy test, el copy ctor crea brain = new Brain(*copy.brain) — por eso hay una copia independiente.
    copy.getBrain()->setIdea(0, "Sleep"); // Cambias idea en copy a "Sleep"

    std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea:     " << copy.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}

/*
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
}
*/