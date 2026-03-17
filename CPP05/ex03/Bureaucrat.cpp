/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:33:04 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:48:51 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat(void) : _name(""), _grade(150)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat " << _name << " Constructor called" << std::endl;

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& before) : _name(before._name)
{
	std::cout << "Copy Constructor called" << std::endl;
	_grade = before._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& before)
{
	if (this != &before)
	{
		_grade = before._grade;
	}
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::signAForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << _name << " couldn't sign "
		          << form.getName() << " because "
		          << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << _name << " couldn’t execute "
		          << form.getName() << " because "
		          << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}