/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:15 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/14 13:05:01 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& before)
	: _name(before._name),
	  _isSigned(before._isSigned),
	  _gradeToSign(before._gradeToSign),
	  _gradeToExecute(before._gradeToExecute),
	  _target(before._target) {}

AForm& AForm::operator=(const AForm& before)
{
	if (this != &before)
		_isSigned = before._isSigned;
	return *this;
}

/* ===== EXCEPCIONES ===== */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

/* ===== LÓGICA COMÚN ===== */

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

/* ===== GETTERS ===== */

const std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
const std::string AForm::getTarget() const { return _target; }

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << "Form " << f.getName()
		<< ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return out;
}
