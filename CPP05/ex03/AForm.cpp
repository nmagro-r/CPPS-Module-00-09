/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:33:28 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:23:53 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name(""), _gradeToSign(150), _gradeToExecute(150)
{
    this->_isSigned = 0;
    std::cout << "Default Form Constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Default Form Destructor called" << std::endl;
}

AForm::AForm( const AForm& before ) : _name(before._name), _isSigned(before._isSigned), _gradeToSign(before._gradeToSign), _gradeToExecute(before._gradeToExecute)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = before;
}

AForm &AForm::operator=(const AForm &before)
{
    if (this != &before)
    {
        _isSigned = before.getIsSigned();
    }
    return *this;
}


std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &t)
{
    os << "Form: " << t.getName()
       << " | Signed: " << (t.getIsSigned() ? "yes" : "no")
       << " | Grade to sign: " << t.getGradeToSign()
       << " | Grade to execute: " << t.getGradeToExecute();
    return os;
}

std::string AForm::getTarget() const
{
    return _target;    
}

void AForm::checkExecution(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

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
