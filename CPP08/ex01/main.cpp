/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:50:55 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/16 18:27:17 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp(5);  // capacidad máxima = 5

        std::vector<int> value;
        value.push_back(3);
        value.push_back(6);
        value.push_back(8);
        value.push_back(9);
        value.push_back(11);
        
        sp.addRange(value.begin(), value.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}