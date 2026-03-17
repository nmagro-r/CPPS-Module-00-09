/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:47:47 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:18:52 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &)
{
	return *this;
}


AForm *createPresi(const std::string &target)
{
	AForm *a = new PresidentialPardonForm(target);
	return (a);
}

AForm *createRobot(const std::string &target)
{
	AForm *a = new RobotomyRequestForm(target);
	return (a);
}

AForm *createShrub(const std::string &target)
{
	AForm *a = new ShrubberyCreationForm(target);
	return (a);
}
// Son pequeñas fábricas específicas, una por cada tipo de formulario.
// Devuelven un puntero dinámico (new ...) a una subclase de AForm

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string names[3] = {"PresidentialPardon", "RobotomyRequest",
						"ShrubberyCreation"};
	int i = 0;
	while (i < 3)
	{
		if (names[i] == name)
			break;
		i++;
	}

	switch (i)
	{
		case 0: return createPresi(target);
		case 1: return createRobot(target);
		case 2: return createShrub(target);
		default: throw FormNotFound();
	}

}

const char* Intern::FormNotFound::what() const throw()
{
	return "Form not found";
}
