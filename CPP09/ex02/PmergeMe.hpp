/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:21 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/25 11:18:42 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <utility>
#include <ctime>

class PmergeMe
{
public:
    PmergeMe(char **argv);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void process();  // Ejecuta todo

private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

    // PARSING
    void parseInput(char **argv); // guarda en vector y en deque;
    bool isNumber(const std::string& str) const; 

    // PRINT
    void printBefore() const; // DO
    void printAfter() const;  // O

    // VECTOR SORT
    void mergeInsertSortVector(std::vector<int>& data); //algoritmo;
    void createPairsVector(const std::vector<int>& data,std::vector<std::pair<int,int> >& pairs); // Agrupamos de 2 en 2;
    void separatePairsVector(const std::vector<std::pair<int,int> >& pairs,std::vector<int>& larger,std::vector<int>& smaller); // guarda el mayor y el menor de cada par;
    void binaryInsertVector(std::vector<int>& data, int value); // llama a search e inserta el value;
    size_t binarySearchVector(const std::vector<int>& data, int value); //  Busca la posición correcta para insertar el value;

    // DEQUE SORT
    void mergeInsertSortDeque(std::deque<int>& data);
    void binaryInsertDeque(std::deque<int>& data, int value);
    size_t binarySearchDeque(const std::deque<int>& data, int value);
};

#endif