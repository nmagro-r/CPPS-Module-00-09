/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:08:03 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 12:10:26 by nmagro-r         ###   ########.fr       */
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

		virtual void makeSound()const = 0;
		std::string getType()const;

	protected:
	
		std::string type;
		
};

#endif
