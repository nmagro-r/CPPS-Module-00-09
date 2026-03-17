/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:51 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:01:20 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5)	
{
	_target = "nadie";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		_target = other.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);
	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}
