/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:03:08 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:31:13 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequest", 72, 45)
{
	_target = "nadie";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequest", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	std::cout << "* DRRRRRRRRR... drilling noises *" << std::endl;

	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}
