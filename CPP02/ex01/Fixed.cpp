 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:42:09 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/17 12:56:26 by nmagro-r         ###   ########.fr       */
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
    std::cout << " Int constructor called" << std::endl; //Al multiplicar el entero por 256 
    fixedNumberValue = intNumber * 256;                  //almacenas su representación fixed.
}

Fixed::Fixed (const float floatNum)
{
    std::cout << " Float constructor called" << std::endl; //al multiplicar por 256 obtienes un número no entero;
    fixedNumberValue = round(floatNum * 256.0f);           // round aproxima al entero más cercano para minimizar el error.
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
    return(fixedNumberValue / 256.0f); //divide el entero escalado por la misma escala 256.0f para recuperar el valor real float.
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
