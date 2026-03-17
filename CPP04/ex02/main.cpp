/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:52:05 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/04 17:32:01 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    return 0;
}
*/

// File: main.cpp
// Ruta del proyecto: ./ (pega junto a tus .cpp/.hpp)
// Compilar con: c++ -Wall -Wextra -Werror -std=c++98 main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp -o ex02

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- POLYMORPHISM & DESTRUCTION TEST ---\n";

    // Nota didáctica: la siguiente línea (si se descomenta) debe fallar en compilación
    // porque Animal es abstracta en ex02 (makeSound() = 0).
    // Animal a; // <-- INTENCIONALMENTE NO COMPILAR

    // 1) Polimorfismo: crear varios animales como Animal*
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    std::cout << "\n-- makeSound() through Animal* (polymorphism) --\n";
    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();

    std::cout << "\n-- deleting animals (should call derived dtors then base dtors) --\n";
    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << "\n--- DEEP COPY TEST (Dog) ---\n";
    Dog dogA;                           // crea Brain internamente
    dogA.getBrain()->setIdea(0, "Eat");
    dogA.getBrain()->setIdea(1, "Play");

    std::cout << "dogA idea[0]: " << dogA.getBrain()->getIdea(0) << "\n";
    std::cout << "dogA idea[1]: " << dogA.getBrain()->getIdea(1) << "\n";

    Dog dogB = dogA;                    // copy ctor -> debe clonar Brain
    std::cout << "\nAfter copy (dogB created):\n";
    std::cout << "dogB idea[0]: " << dogB.getBrain()->getIdea(0) << "\n";

    // Cambiamos la copia y comprobamos que el original NO cambia
    dogB.getBrain()->setIdea(0, "Sleep");
    std::cout << "\nAfter changing dogB idea[0]:\n";
    std::cout << "dogA idea[0]: " << dogA.getBrain()->getIdea(0) << "  (expected: Eat)\n";
    std::cout << "dogB idea[0]: " << dogB.getBrain()->getIdea(0) << "  (expected: Sleep)\n";

    std::cout << "\n--- DEEP COPY TEST (Cat) ---\n";
    Cat catA;
    catA.getBrain()->setIdea(0, "Hunt");
    Cat catB(catA);                     // copy ctor
    catB.getBrain()->setIdea(0, "Nap");

    std::cout << "catA idea[0]: " << catA.getBrain()->getIdea(0) << "  (expected: Hunt)\n";
    std::cout << "catB idea[0]: " << catB.getBrain()->getIdea(0) << "  (expected: Nap)\n";

    std::cout << "\n--- END (no leaks if Brain deleted in destructors) ---\n";
    return 0;
}


