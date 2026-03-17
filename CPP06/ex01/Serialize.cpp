/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:36:30 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/02 19:32:20 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const &other)
{
	(void)other;
}

Serializer::~Serializer(void)
{}

Serializer& Serializer::operator=(Serializer const &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}