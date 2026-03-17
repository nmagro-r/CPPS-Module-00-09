/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:27:41 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/19 15:18:49 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& databaseFile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);

		void processInput(const std::string& filename); //Abrir archivo input.txt, leer linea por linea, parsear fecha y valor y validar;Luego llamar a findcloset..imprimir resultado o error;
		
	private:
		std::map<std::string, double> _database; //Red black tree - contenedror STL
		void 	loadDatabase(const std::string& filename); //abrir data.csv, leer linea a linea, separar fecha y precio e insertar en database;
		double 	findClosestRate(const std::string& date) const; //Buscar la fecha en _database, si existe->devolver precio exacto, si no existe usar lower-bound, devolver precio inferior más cercano;
		bool   	parseDatabaseLine(const std::string& line,std::string& date,double& price) const;
		bool 	isValidDate(const std::string& date) const; //Debe comprobar formato, año valido, mes 1-12, día válido según mes, año bisiesto;
		bool 	isValidValue(double value) const; // Debe between 0 and 1000;

		
};

#endif
