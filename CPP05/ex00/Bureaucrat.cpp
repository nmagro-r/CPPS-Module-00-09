/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:49:41 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/01/09 19:42:00 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** Constructor por defecto
** - name se inicializa vacío
** - grade se inicializa al peor rango válido (150)
*/
Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
}

/*
** Constructor principal
** - Inicializa el nombre (const)
** - Valida el grade
** - Si es inválido, lanza excepción
** - NO captura aquí: si falla, el objeto no debe existir
*/
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

/*
** Destructor
*/
Bureaucrat::~Bureaucrat()
{
}

/*
** Constructor de copia
** - name (const) se copia en la lista de inicialización
** - grade se copia dentro del cuerpo
*/
Bureaucrat::Bureaucrat(const Bureaucrat& before)
	: name(before.name), grade(before.grade)
{
}

/*
** Operador de asignación
** - NO toca _name (es const)
** - Solo copia el estado modificable (grade)
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& before)
{
	if (this != &before)
	{
		grade = before.grade;
	}
	return *this;
}

/*
** Incrementa el rango (mejora)
** - Resta 1 al grade
** - Si ya está en 1, lanza excepción
*/
void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	--grade;
}

/*
** Decrementa el rango (empeora)
** - Suma 1 al grade
** - Si ya está en 150, lanza excepción
*/
void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	++grade;
}

/*
** Getter del grade
*/
int Bureaucrat::get_Grade() const
{
	return grade;
}

/*
** Getter del nombre
*/
const std::string Bureaucrat::get_Name() const
{
	return name;
}

/*
** Implementación de what() de las excepciones
*/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


/*
** Sobrecarga del operador <<
** - Formato exacto pedido por el subject
*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.get_Name() << ", bureaucrat grade " << b.get_Grade() << ".";
	return out;
}
