/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:50:20 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/04 17:33:42 by nmagro-r         ###   ########.fr       */
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
        Brain* getBrain() const;
	
	private:

		Brain *brain;

    
};

#endif