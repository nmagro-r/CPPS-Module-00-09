/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:54:01 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 16:06:08 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    try
    {
        AForm *form = intern.makeForm("PresidentialPardon", "Bender");
        std::cout << "Form created: " << form->getName() << std::endl;
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n";
    try
    {
        AForm *form = intern.makeForm("UnknownForm", "Nowhere");
        (void)form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}