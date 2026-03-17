/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:50:13 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/09 19:41:53 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b0("b0", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b1("b1", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b2("b2", 1);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "Decrement: " << b2 << std::endl;                                                                       
		b2.incrementGrade();
		std::cout << "Increment: " << b2 << std::endl;
		b2.incrementGrade();
		std::cout << "Increment: " << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b2("b2", 150);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << "Increment: " << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "Decrement: " << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "Decrement: " << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}