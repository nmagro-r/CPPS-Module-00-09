/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:20:52 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/04 13:12:55 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	public:
		virtual ~Base(void) {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif

//Base es una clase polimórfiica.
//Sin virtual no funcionaria dynamic_cast
//Sirve como interfaz común.
//Permite tratar A, B, C como Base.