/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:46:50 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/09 17:21:01 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

// Version para arrays NO const
template <typename T, typename F>
void iter(T* array, std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

// Version para arrays const
template <typename T, typename F>
void iter(const T* array, std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif
