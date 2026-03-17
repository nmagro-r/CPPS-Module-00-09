/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:04 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/25 13:41:12 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>  

PmergeMe::PmergeMe(char **argv)
{
	parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	_vector = other._vector;
	_deque = other._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if(this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::process()
{
	printBefore();
	
	std::clock_t startVec = std::clock(); // restando end - start tendremos ticks consumidos / nº de ticks(unidad interna del procesador);
	mergeInsertSortVector(_vector);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
    mergeInsertSortDeque(_deque);
    std::clock_t endDeq = std::clock();

	printAfter();

	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of "
              << _vector.size()
              << " elements with std::vector : "
              << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of "
              << _deque.size()
              << " elements with std::deque : "
              << timeDeq << " us" << std::endl;
}

void PmergeMe::parseInput(char **argv)
{
    for (int i = 1; argv[i]; ++i) // recorremos solo los argumentos válidos
    {
        if (argv[i] == NULL) // C++98 usa NULL
            throw std::runtime_error("Error: argumento nulo");

        std::string str(argv[i]);

        if (!isNumber(str)) // tu función para validar que sea número
            throw std::runtime_error("Error: argumento no numérico");

        char *endptr = NULL;
        long num = strtol(argv[i], &endptr, 10); 

        if (*endptr != '\0') // si no se consumió todo el string, es inválido
            throw std::runtime_error("Error: número inválido");

        if (num < 0 || num > 2147483647) // rango de int
            throw std::runtime_error("Error: número fuera de rango");

        _vector.push_back(static_cast<int>(num));
        _deque.push_back(static_cast<int>(num));
    }
}

bool PmergeMe::isNumber(const std::string& str) const
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); ++i)
        if (!std::isdigit(str[i]))
            return false;

    return true;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After:  ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

//   VECTOR FORD-JOHNSON     

void PmergeMe::mergeInsertSortVector(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

    std::vector<std::pair<int,int> > pairs; // creamos vector vacío de pares;
    createPairsVector(data, pairs);

    std::vector<int> larger;
    std::vector<int> smaller;
    separatePairsVector(pairs, larger, smaller);

    mergeInsertSortVector(larger);

    data = larger;

    for (size_t i = 0; i < smaller.size(); ++i)
        binaryInsertVector(data, smaller[i]);
}

void PmergeMe::createPairsVector(const std::vector<int>& data,std::vector<std::pair<int,int> >& pairs)
{
    size_t i = 0;

    while (i + 1 < data.size())
    {
        int a = data[i];
        int b = data[i + 1];

        if (a > b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
        i += 2;
    }

    if (i < data.size())
        pairs.push_back(std::make_pair(data[i], -1));
}

void PmergeMe::separatePairsVector(const std::vector<std::pair<int,int> >& pairs,std::vector<int>& larger,std::vector<int>& smaller)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second == -1)
        {
            larger.push_back(pairs[i].first); // impares ->añadimos a larger;
        }
        else
        {
            smaller.push_back(pairs[i].first);
            larger.push_back(pairs[i].second);
        }
    }
}

void PmergeMe::binaryInsertVector(std::vector<int>& data, int value)
{
    size_t pos = binarySearchVector(data, value);
    data.insert(data.begin() + pos, value);
}

size_t PmergeMe::binarySearchVector(const std::vector<int>& data, int value)
{
    size_t left = 0;
    size_t right = data.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;

        if (data[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

// DEQUE FORD - JOHNSON


void PmergeMe::mergeInsertSortDeque(std::deque<int>& data)
{
    if (data.size() <= 1)
        return;

    std::deque<std::pair<int,int> > pairs;
    size_t i = 0;

    while (i + 1 < data.size())
    {
        int a = data[i];
        int b = data[i + 1];

        if (a > b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
        i += 2;
    }

    if (i < data.size())
        pairs.push_back(std::make_pair(data[i], -1));

    std::deque<int> larger;
    std::deque<int> smaller;

    for (size_t j = 0; j < pairs.size(); ++j)
    {
        if (pairs[j].second == -1)
        {
            larger.push_back(pairs[j].first);
        }
        else
        {
            smaller.push_back(pairs[j].first);
            larger.push_back(pairs[j].second);
        }
    }

    mergeInsertSortDeque(larger);

    data = larger;

    for (size_t k = 0; k < smaller.size(); ++k)
        binaryInsertDeque(data, smaller[k]);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& data, int value)
{
    size_t pos = binarySearchDeque(data, value);
    data.insert(data.begin() + pos, value);
}

size_t PmergeMe::binarySearchDeque(const std::deque<int>& data, int value)
{
    size_t left = 0;
    size_t right = data.size();

    while (left < right)
    {
        size_t mid = (left + right) / 2;

        if (data[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}