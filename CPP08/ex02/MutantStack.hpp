/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:12:35 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/16 18:44:42 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <list>


template <typename T>
class MutantStack : public std::stack<T> // container adaptor->no almacena datos directamente(usa deque x defecto)
{
    public:
        MutantStack() : std::stack<T>(){} //heredamos públicamente y podemos acceder a this->c()
        MutantStack(const MutantStack &copy): std::stack<T>(copy){}
        MutantStack &operator=(const MutantStack &copy)
        {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return *this;
        }
        ~MutantStack(){}
      	typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

        const_iterator begin() const
        {
            return this->c.begin();
        }

        const_iterator end() const
        {
            return this->c.end();
        }
};

#endif