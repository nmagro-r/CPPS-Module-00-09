/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:07:39 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/09 12:40:11 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{   
    public:
    
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal(std::string type);
        WrongAnimal &operator=(const WrongAnimal &copy);
        ~WrongAnimal();
    
        void makeSound() const; // Sin virtual
        std::string getType()const;
        

        
    protected:
        std::string type;

};


#endif