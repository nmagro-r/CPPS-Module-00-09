/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:24:19 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/10 17:43:16 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>


template<typename T>
class Array
{
    public: 
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        ~Array();

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfRange : public std::exception
        {
            public: 
                const char *what()const throw()
                {
                    return ("out of boundaries");
                }
        };
    
    private: 
        T *elements;
        unsigned int _size;
};


template  <typename T>
Array<T>::Array() : elements(NULL), _size(0)
{
    std::cout << "default constructor" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
    std::cout << "default destructor" << std::endl;
}

template <typename T>

Array<T>::Array(unsigned int n) : _size(n)
{
    elements = new T[n];  // reserva espacio para n objetos de tipo T. Se llama al constructor default.
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    if (this != &copy)
    {
        this->_size = copy._size;
        this->elements = new T[this->_size]();
        for (unsigned int i = 0; i < _size; i++)
        {
            this->elements[i] = copy.elements[i];
        }
    }
}


template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        delete[] this->elements;
        this->_size = copy._size;
        this->elements = new T[this->_size]();
        for (unsigned int i = 0; i < _size; i++)
        {
            this->elements[i] = copy.elements[i];
        }
    }
    return *this;
}


template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}


template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return elements[index];
}



#endif