/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:47:55 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/14 12:48:01 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Orthodox Canonical */

Form::Form()
	: _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) 
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& before)
	: _name(before._name),
	  _isSigned(before._isSigned),
	  _gradeToSign(before._gradeToSign),
	  _gradeToExecute(before._gradeToExecute) {}

Form& Form::operator=(const Form& before)
{
	if (this != &before)
		_isSigned = before._isSigned;
	return *this;
}

/* Excepciones */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

/* Métodos */

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/* Getters */

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

/* operator << */

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form " << f.getName()
		<< ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return out;
}
