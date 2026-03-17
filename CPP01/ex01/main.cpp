/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:46:24 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/30 16:17:52 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 3;
    Zombie *horde = zombieHorde(N, "Horde");

    for (int i = 0; i < N; i++) {
        std::cout << "Index " << i << ": ";
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}
