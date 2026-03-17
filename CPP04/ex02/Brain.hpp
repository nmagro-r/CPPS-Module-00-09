/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:24:47 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/04 17:25:12 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
  
    public:

        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        ~Brain();


        
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const; 
        
        
    private:
        std::string ideas[100];
        
    
};


#endif