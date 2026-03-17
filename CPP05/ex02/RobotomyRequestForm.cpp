/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:03:26 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/14 13:07:07 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy", 72, 45)
{
	_target = "nadie";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		_target = other.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);

	std::cout << "* drilling noises *" << std::endl;

	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}
