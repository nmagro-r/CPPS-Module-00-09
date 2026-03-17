/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:52:52 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:49:15 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& name, const std::string& target);

		class FormNotFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
