/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:19:46 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/26 15:18:29 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN &other)
{
	if(this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}


bool RPN::isNumber(const std::string &token) const
{
    if (token.length() != 1)
        return false;
    return std::isdigit(static_cast<unsigned char>(token[0]));
}

bool RPN::isOperator(const std::string &token) const
{
    if (token.length() != 1)
        return false;

    char c = token[0];
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(int a, int b, char op) const
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }

    throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string &expression)
{
    // Vaciar la pila por seguridad
    while (!_stack.empty())
        _stack.pop();

    std::stringstream ss(expression); // Convierte el string. Permite leer los tokens separados por espacios;
    std::string token;

    while (ss >> token) // Iteramos;
    {
        if (isNumber(token))
        {
            _stack.push(token[0] - '0');// Convertimos carácter en num entero;
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2) // necesitamos 2 operandos;
                throw std::runtime_error("Error");

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            int result = applyOperator(a, b, token[0]);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1) // Tiene que haber un único resultado;
        throw std::runtime_error("Error");

    return _stack.top();
}
