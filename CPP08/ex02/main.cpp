/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:12:04 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/16 18:35:50 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include "MutantStack.hpp"


int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
        
    return 0;
}


// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);    
//     mstack.push_back(17); 
//     std::cout << mstack.back() << std::endl;
    
//     mstack.pop_back();
    
//     std::cout << mstack.size() << std::endl;
    
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     mstack.push_back(0);
    
//     std::list<int>::const_iterator it = mstack.begin();
//     std::list<int>::const_iterator ite = mstack.end();
    
//     ++it;
//     --it;
    
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
    
//     return 0;
// }
