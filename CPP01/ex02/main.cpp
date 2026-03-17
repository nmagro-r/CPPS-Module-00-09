/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:46:14 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/12 16:51:33 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
int main()
{
    std::string var1 = "HI THIS IS BRAIN";
    std::string *ptr = &var1;
    std::string &ref = var1;

    std::cout << "address of var1: " << &var1 << std::endl;
    std::cout << "address of ptr: " << ptr << std::endl;
    std::cout << "address of ref: " << &ref << std::endl;

    std::cout << var1 << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;
    
}