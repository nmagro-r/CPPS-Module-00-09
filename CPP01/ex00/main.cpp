/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:52:46 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/22 15:54:42 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

    randomChump("ChumpZombie");

    Zombie *heapzombie = newZombie("heapzombie");
    heapzombie->announce();
    delete heapzombie;

    randomChump("StackZombie");
    return(0);
}