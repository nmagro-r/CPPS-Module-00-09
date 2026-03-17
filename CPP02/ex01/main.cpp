/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:41:52 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/17 13:04:51 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include"Fixed.hpp"
int main( void ) 
{
    Fixed a; //constr por defecto.
    Fixed const b( 10 ); //llama a constructor fixed(int). b = 10*256
    Fixed const c( 42.42f ); //llama a constr fixed(float). Almacena 42.42*256
    Fixed const d( b ); //constr de copia
    a = Fixed( 1234.4321f ); //Crea un temporal con el float-constr, luego llama a operator=sobre a, para copiar el raw y luego se estruye.
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
