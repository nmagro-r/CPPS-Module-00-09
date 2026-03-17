/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:23:42 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/12/04 17:23:59 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i <  100; i++)
        this->ideas[i] = "";
}

//iniciar el array en el constructor por defecto.

Brain::Brain(const Brain &copy)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = copy. ideas[i];
}

//bucle para asignar idea a cada posicion

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = copy. ideas[i];
    }
    return(*this);
}

//mismo bucle para operador de asignacion.

Brain::~Brain()
{

}

void Brain::setIdea(int i, std::string idea)
{
    if (i >= 0 && i < 100)
        ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    if (i >= 0 && i < 100)
        return(ideas[i]);
    return("");
}