/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:22:14 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/30 16:15:00 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        std::string fullName = name;
        fullName += " ";

        fullName += (i + 1) + '0';

        horde[i].setName(fullName);
    }
    return (horde);
}
