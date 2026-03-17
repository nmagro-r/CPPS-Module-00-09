/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:10:20 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/23 16:19:04 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <vector> 
#include <stack>
#include <iostream> 
#include <sstream> 
#include <cstdlib> 
#include <exception> 
#include <stdexcept>

class RPN
{
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression);

private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const; // -verifica si el token es: + - * /;
    bool isNumber(const std::string& token) const; // Validar que el token sea num válido;
    int  applyOperator(int a, int b, char op) const; // aplica op.matemática;
};

#endif