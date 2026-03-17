/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:37:45 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/09 19:44:02 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& before);
		Bureaucrat& operator=(const Bureaucrat& before);

		// Excepciones (solo declaración)
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void incrementGrade();
		void decrementGrade();

		int getGrade() const;
		const std::string getName() const;

		void signAForm(AForm& form) const;
		void executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
