/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:36:10 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/02 19:30:12 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include <cstddef>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &other);
		~Serializer(void);
		Serializer &operator=(Serializer const &other);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
