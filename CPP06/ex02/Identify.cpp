/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:30:11 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/05 17:15:02 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	static bool seeded = false;
	
	if(!seeded)
	{
		std::srand((std::time(NULL)));
		seeded = true;
	}
	int r = rand() % 3;
	if(r == 0)
		return new A;
	else if( r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if(dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if(dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown type\n";
}

//Intenta convertir Base* -> A*

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch(std::bad_cast&)
	{}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch(std::bad_cast&)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch(std::bad_cast&)
	{}
	
	std::cout << "Unknown type\n";
	
}