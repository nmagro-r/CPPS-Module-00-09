/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:17:18 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/12 16:49:11 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    std::string complainType;
    Harl Harl;

    std::cout << "Choose you type of complain (DEBUG, INFO, WARNING or ERROR): " << std::endl;
    std::cin >> complainType;

    Harl.complain(complainType);
    return(0);
}