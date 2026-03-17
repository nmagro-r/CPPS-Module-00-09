/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:27:27 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/19 18:55:14 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}


void BitcoinExchange::loadDatabase(const std::string& filename) // lee el archivo .csv y guarda fechas y precios en std::map
{
    std::ifstream file(filename.c_str()); //Crea objeto que representa el archivo;
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::string date;
        double price;

        if (parseDatabaseLine(line, date, price))
            _database.insert(std::make_pair(date, price));//make_pair crea un std::pair automáticamente; El map guarda pares (clave, valor)
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr  = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr   = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); ++i)
        if (!isdigit(yearStr[i]))
            return false;

    for (size_t i = 0; i < monthStr.length(); ++i)
        if (!isdigit(monthStr[i]))
            return false;

    for (size_t i = 0; i < dayStr.length(); ++i)
        if (!isdigit(dayStr[i]))
            return false;

    int year  = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day   = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); //año bisiesto;
        daysInMonth = isLeap ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(double value) const
{
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    return true;
}

bool BitcoinExchange::parseDatabaseLine(const std::string& line,std::string& date,double& price) const
{
    std::size_t comma = line.find(',');
    if (comma == std::string::npos) //npos = no encontrado;
        return false;

    date = line.substr(0, comma);
    std::string priceStr = line.substr(comma + 1);

    if (!isValidDate(date))
        return false;

    std::stringstream ss(priceStr); //lee texto y pasamos a double.
    ss >> price;
    if (ss.fail())
        return false;

    return true;
}

double BitcoinExchange::findClosestRate(const std::string& date) const //Encontratr el precio de una fecha, si no existe, la cercana anterior.
{
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
        return it->second;

    if (it == _database.begin())
        throw std::runtime_error("Error: no earlier date available.");

    --it; // fecha inferior
    return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) //lee el archivo del usuario
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::size_t pipe = line.find('|');
        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe - 1);
        std::string valueStr = line.substr(pipe + 2);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::stringstream ss(valueStr);
        double value;
        char extra;

        if (!(ss >> value) || (ss >> extra)) //extra intenta leer cualquier carácter adicional.
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }


        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            double rate = findClosestRate(date); // value es cantidad de bitcoins que tiene el usuario y rate el prcio del bitcoin ese dia;
            std::cout << date << " => " << value
                      << " = " << value * rate << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}


