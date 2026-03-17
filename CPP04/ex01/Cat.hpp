/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:28:37 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/03 12:08:34 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();
    
        void makeSound()const;
        std::string getType()const;
	
	private:

		Brain *brain;

    
};

#endif