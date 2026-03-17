/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:36:21 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/16 18:21:45 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);
    nums.push_back(50);

    try
    {
        std::vector<int>::iterator it = easyfind(nums, 30);
        std::cout << "Encontrado: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        easyfind(nums, 100);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}