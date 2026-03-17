/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:53:31 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/09 18:57:45 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
    std::cout << "INT TEST\n";
    try
    {
        Array<int> a(10); // tamaño 10
        for (unsigned int i = 0; i < a.size(); i++){
            a[i] = i + 1;
            std::cout <<"Array["<<i<<"]-> " <<a[i] << std::endl;
        }
        std::cout << "size: " << a.size() << std::endl;
        // FORZAR EXCEPCIÓN
        std::cout << "Accessing out-of-bounds index...\n";
        a[20] = 42; // índice fuera de rango
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\nDOUBLE TEST\n";
    try
    {
        Array<double> a(10);
        for (unsigned int i = 0; i < a.size(); i++){
            a[i] = i + 0.5;
            std::cout <<"Array["<<i<<"]-> " <<a[i] << std::endl;
        }
        std::cout << "size: " << a.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\nCHAR TEST\n";
    try
    {
        Array<char> a(10);
        for (unsigned int i = 0; i < a.size(); i++){
            a[i] = i + 65;
            std::cout <<"Array["<<i<<"]-> " <<a[i] << std::endl;
        }
        std::cout << "size: " << a.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\nCOPY TEST\n";
    try
    {
        Array<char> a(10);
        for (unsigned int i = 0; i < a.size(); i++){
            a[i] = i + 65;
        }
        Array<char> b = a; // constructor de copia
        // Modificar 'a' para verificar deep copy
        for (unsigned int i = 0; i < a.size(); i++){
            a[i] = a[i] + 1;
            std::cout << "a: " << a[i] << " | b: " << b[i] << std::endl;
        }
        std::cout << "size a: " << a.size() << ", size b: " << b.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}