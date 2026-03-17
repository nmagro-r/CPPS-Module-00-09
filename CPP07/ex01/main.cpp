/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:47:04 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/09 17:29:32 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Función que MODIFICA el elemento
void increment(int &x)
{
    ++x;
}

// Función template que SOLO LEE el elemento
template <typename T>
void printValue(const T &x)
{
    std::cout << x << " ";
}

int main()
{
    // ---------- Array NO const ----------
    int intArr[] = {1, 2, 3, 4};

    std::cout << "Original int array: ";
    iter(intArr, 4, printValue<int>);
    std::cout << std::endl;

    iter(intArr, 4, increment);

    std::cout << "After increment: ";
    iter(intArr, 4, printValue<int>);
    std::cout << std::endl;


    // ---------- Array CONST ----------
    const int constIntArr[] = {10, 20, 30};

    std::cout << "Const int array: ";
    iter(constIntArr, 3, printValue<int>);
    std::cout << std::endl;


    // ---------- Otro tipo ----------
    std::string strArr[] = {"hello", "world", "42"};

    std::cout << "String array: ";
    iter(strArr, 3, printValue<std::string>);
    std::cout << std::endl;

    return 0;
}
