/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:30:29 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/04 14:19:59 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Identify.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base* base = generate();

    std::cout << "Identify using pointer: ";
    identify(base);

    std::cout << "Identify using reference: ";
    identify(*base);

    delete base;
    return 0;
}