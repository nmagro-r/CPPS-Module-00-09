/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:20:01 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/17 13:35:30 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixedNumberValue = 0;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << " Int constructor called" << std::endl;
    fixedNumberValue = intNumber * 256; 
}

Fixed::Fixed (const float floatNum)
{
    std::cout << " Float constructor called" << std::endl;
    fixedNumberValue = round(floatNum * 256.0f);
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        fixedNumberValue = copy.fixedNumberValue;
    std::cout << "copy assingment operator called" << std::endl;
    return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void)const
{
   return(fixedNumberValue / 256.0f);
}

int Fixed::toInt(void)const
{
   return(fixedNumberValue / 256); 
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
  out << fixed.toFloat();
  return(out);
}

bool  Fixed::operator<(const Fixed &copy)const
{
    return(fixedNumberValue < copy.fixedNumberValue);
}

bool  Fixed::operator>(const Fixed &copy)const
{
    return(fixedNumberValue > copy.fixedNumberValue);
}
bool  Fixed::operator>=(const Fixed &copy)const
{
    return(fixedNumberValue >= copy.fixedNumberValue);
}

bool  Fixed::operator<=(const Fixed &copy)const
{
    return(fixedNumberValue <= copy.fixedNumberValue);
}

bool  Fixed::operator==(const Fixed &copy)const
{
    return(fixedNumberValue == copy.fixedNumberValue);
}

bool  Fixed::operator!=(const Fixed &copy)const
{
    return(fixedNumberValue != copy.fixedNumberValue);
}

//aritmetica

Fixed Fixed::operator+(const Fixed &copy) const
{
    Fixed result;
    result.fixedNumberValue = this->fixedNumberValue + copy.fixedNumberValue;
    return(result);
}

Fixed Fixed::operator-(const Fixed &copy) const
{
    Fixed result;
    result.fixedNumberValue = this->fixedNumberValue - copy.fixedNumberValue;
    return(result);
}

Fixed Fixed::operator*(const Fixed &copy) const
{
    Fixed result;
    result.fixedNumberValue = (this->fixedNumberValue * copy.fixedNumberValue) / 256;
    return(result);
}

Fixed Fixed::operator/(const Fixed &copy) const
{
    Fixed result;
    result.fixedNumberValue = (this->fixedNumberValue * 256) / copy.fixedNumberValue;
    return(result);
}

//incremento

//pre

Fixed &Fixed::operator++()
{
    ++fixedNumberValue;
    return(*this);
}
Fixed &Fixed::operator--()
{
    --fixedNumberValue;
    return(*this);
}

//primero lo modificamos y luego lo devolvemos

//post

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    fixedNumberValue++;
    return(temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    fixedNumberValue--;
    return(temp);
}


//min and max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return(a);
    else
        return(b);
}

const Fixed &Fixed:: min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return(a);
    else
        return(b);
}


Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return(a);
    else
        return(b);
}

const Fixed &Fixed:: max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return(a);
    else
        return(b);
}

//creamos una copia que modificamos y devolvemos el original.