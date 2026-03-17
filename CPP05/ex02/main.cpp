/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:13:37 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/14 13:14:00 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Trillian");
    ShrubberyCreationForm tardon("Meg");
    std::cout << "\n";

    try
    {
        boss.signAForm(robot);
        boss.executeForm(robot);
        std::cout << "\n";

        boss.signAForm(pardon);
        boss.executeForm(pardon);
        std::cout << "\n";

        boss.signAForm(tardon);
        boss.executeForm(tardon);
        std::cout << "\n";
    } catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}