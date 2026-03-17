/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:06:19 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/09 12:37:24 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:

		Animal();
		Animal(const Animal &copy);
		Animal(std::string name);
		Animal &operator=(const Animal &copy);
		virtual ~Animal();

		virtual void makeSound()const; // virtual. Permite que las llamadas sobre punteros a Animal, ejecuten la implementación de la clase concreta(Dog/Cat)
		std::string getType()const;

	protected:
	
		std::string type;
		
};

#endif
