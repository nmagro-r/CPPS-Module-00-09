/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:46:05 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/09 19:42:28 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* Orthodox Canonical */

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& before)
	: _name(before._name), _grade(before._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& before)
{
	if (this != &before)
		_grade = before._grade;
	return *this;
}

/* Excepciones */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

/* Métodos */

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn’t sign "
				  << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

/* operator << */

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
