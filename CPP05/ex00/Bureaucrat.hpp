/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:50:04 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/09 19:42:09 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& before);
		Bureaucrat& operator=(const Bureaucrat& before);

		// Excepciones propias del Bureaucrat
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void decrementGrade();
		void incrementGrade();

		int get_Grade() const;
		const std::string get_Name() const;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &classToPrint);

#endif

// Las excepciones son alarmas, y viven dentro de clases, porque solo tienen sentido ahi.
// What es el mensaje para humanos.
// Throw sirve para lanzar una excepción cuando ocurre un error.
// std::exception - permite que todos los errores se traten igual y define la funcion what(que devuelve un mensaje). (por esos heredamos el exception tb)
// Todas mis excepciones son std::exception - Gradetoohigh,Gradetoolow, u otras futuras. (polimorfismo aplicado a errores)
// Heredar de std::exception es decir: 'Este error se comporta como un error C++ normal'.
 