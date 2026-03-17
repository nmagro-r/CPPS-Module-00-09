/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:51:14 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/16 11:56:07 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0)
{}

Span::Span(unsigned int N): _N(N)
{
	_numbers.reserve(N); // evitamos reallocations innecesarias
}

Span::Span(const Span& other): _numbers(other._numbers), _N(other._N)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_N = other._N;
		this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}



void Span::addNumber(int nb)
{
	if (_numbers.size() >= _N)
		throw MaxCapacity();
	_numbers.push_back(nb);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanFound();

    std::vector<int> sortedVec = _numbers;
    
    std::sort(sortedVec.begin(), sortedVec.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedVec.size(); ++i)
    {
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanFound();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}