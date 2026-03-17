/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:09:14 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:31:59 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery", 145, 137)
{
	_target = "nadie";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other) {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		_target = other.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkExecution(executor);

	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("Could not open file");

	print_tree(ofs);
	ofs.close();
}

void ShrubberyCreationForm::print_tree(std::ofstream& ofs) const
{
	ofs << "   ^\n";
	ofs << "  ^^^\n";
	ofs << " ^^^^^\n";
	ofs << "   |\n";
}

