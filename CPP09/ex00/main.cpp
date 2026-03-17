/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:27:07 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/19 18:57:38 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc("data.csv");
        btc.processInput(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
