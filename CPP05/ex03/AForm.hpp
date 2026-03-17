/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:52:42 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/15 15:37:41 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
		std::string _target;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& before);
		AForm& operator=(const AForm& before);

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat& bureaucrat);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		std::string getTarget() const;

		virtual void execute(Bureaucrat const& executor) const = 0;
		void checkExecution(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
