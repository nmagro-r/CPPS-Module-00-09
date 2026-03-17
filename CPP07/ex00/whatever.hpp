/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:38:46 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/10 18:00:32 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include<iostream>

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(T const &a, T const &b)
{
	if(a < b)
		return a;
	return b;
}

template<typename T>
T max(T const &a, T const &b)
{
	if(a > b)
		return a;
	return b;
}

#endif