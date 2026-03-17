/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:15:32 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/17 11:53:50 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include<string>

class Fixed
{
public:
    Fixed();                               // Constructor por defecto
    Fixed(const Fixed &copy);              // Constructor de copia que crea uno a raiz de uno que ya existe
    Fixed& operator=(const Fixed &copy);   // Operador de = que asigna que trabaja con dos que ya existen
    ~Fixed();                              // Destructor

    int getRawBits(void) const;            // Devuelve el valor interno (int)
    void setRawBits(int const raw);        // Asigna el valor interno (int)

private:
    int fixedNumberValue;                  // Valor en punto fijo (entero)
    static const int fractional = 8;       // Bits fraccionales (constante)(cuantos bits reservamos)
};

#endif