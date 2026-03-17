/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:51:00 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/27 14:59:17 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		void announce(void);
		void setName(std::string newName);
	
	private:
		std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif