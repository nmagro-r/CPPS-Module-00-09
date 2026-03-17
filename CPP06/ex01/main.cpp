/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:25:03 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/02 19:29:34 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main() {
    Data data = {42, "OpenAI", 3.14f};

    std::cout << "Original Data pointer: " << &data << std::endl;

    // Convertimos el puntero a entero
    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "Serialized value (raw): " << raw << std::endl;

    // Lo reconvertimos a puntero
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Deserialized pointer:   " << restored << std::endl;

    // Verificamos que apunta al mismo objeto
    std::cout << "ID: " << restored->id << ", Name: " << restored->name
              << ", Value: " << restored->value << std::endl;

    return 0;
}