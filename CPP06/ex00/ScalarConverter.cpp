/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:43:52 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/05 16:45:34 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <climits>
#include <limits>

// Constructores y operadores

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return *this;
}

// Funciones auxiliares

static bool isPseudoLiteral(const std::string &s)
{
    return (
        s == "nan"  || s == "nanf"  ||
        s == "+inf" || s == "+inff" ||
        s == "-inf" || s == "-inff"
    );
}

static bool isSingleCharCandidate(const std::string &s)
{
    if (s.size() != 1)
        return false;

    unsigned char ch = static_cast<unsigned char>(s[0]);

    if (!std::isprint(ch))
        return false;
    if (std::isdigit(ch))
        return false;
    if (ch == '+' || ch == '-' || ch == '.')
        return false;

    return true;
}

static bool isIntLiteral(const std::string &s)
{
    if (s.empty())
        return false;

    std::size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
    {
        if (s.size() == 1)
            return false;
        ++i;
    }

    for (; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }

    return true;
}

static bool isFloatLiteral(const std::string &s)
{
    if (s.size() < 2 || s[s.size() - 1] != 'f')
        return false;

    std::string core = s.substr(0, s.size() - 1);

    bool hasDigit = false;
    bool hasDot   = false;
    std::size_t i = 0;

    if (core[i] == '+' || core[i] == '-')
    {
        if (core.size() == 1)
            return false;
        ++i;
    }

    for (; i < core.size(); ++i)
    {
        char c = core[i];

        if (c == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c)))
            hasDigit = true;
  
        else
            return false;
    }

    if(hasDigit == true && hasDot == true)
        return hasDigit;
    return false;
}

static bool isDoubleLiteral(const std::string &s)
{
    if (s.empty())
        return false;

    bool hasDigit = false;
    bool hasDot   = false;
    std::size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
    {
        if (s.size() == 1)
            return false;
        ++i;
    }

    for (; i < s.size(); ++i)
    {
        char c = s[i];

        if (c == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c)))
            hasDigit = true;
        else
            return false;
    }

    return hasDigit;
}

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, PSEUDO, UNKNOWN };

static LiteralType detectType(const std::string &s)
{
    if (isPseudoLiteral(s))       return PSEUDO;
    if (isSingleCharCandidate(s)) return CHAR;
    if (isIntLiteral(s))          return INT;
    if (isFloatLiteral(s))        return FLOAT;
    if (isDoubleLiteral(s))       return DOUBLE;
    return UNKNOWN;
}

// MÉTODO PRINCIPAL 

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);

    char   c = 0;
    int    i = 0;
    float  f = 0.0f;
    double d = 0.0;

    bool intImpossible  = false;

    switch (type)
{
    case CHAR:
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        break;

    case INT:
        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        break;

    case FLOAT:
        f = std::atof(literal.c_str());
        i = static_cast<int>(f);
        c = static_cast<char>(i);
        d = static_cast<double>(f);
        break;

    case DOUBLE:
        d = std::atof(literal.c_str());
        i = static_cast<int>(d);
        c = static_cast<char>(i);
        f = static_cast<float>(d);
        break;

    case PSEUDO:
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (literal[literal.size() - 1] == 'f')
        {
            std::cout << "float: " << literal << '\n';
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << '\n';
        }
        else
        {
            std::cout << "float: " << literal << "f\n";
            std::cout << "double: " << literal << '\n';
        }
        return;

    default:
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
}

    // CHAR
    if (intImpossible || i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";

    // INT
    if (intImpossible)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << '\n';

    // FLOAT
    std::cout << std::fixed << std::setprecision(1); //confixed escribimos siempre con punto decimal. setPrecision es para determinar cuantos numeros hay después del punto.
    std::cout << "float: " << f << "f\n";

    // DOUBLE
    std::cout << "double: " << d << '\n';
}
