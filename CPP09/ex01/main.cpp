/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:58:37 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/23 16:45:02 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        RPN calculator; // Creamos objeto;
        int result = calculator.evaluate(argv[1]); // llamamos a evaluate;
        std::cout << result << std::endl; // Imprimimos result;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
