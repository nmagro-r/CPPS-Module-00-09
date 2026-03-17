/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:36:14 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/14 12:37:29 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>// para std::find
#include <exception>// para lanzar excepciones

class ValueError : public std::exception
{
	public:
		const char *what() const throw()
        {
			return ("Value not found in container.");
	    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end())
		throw (ValueError());
	return it;
}

#endif