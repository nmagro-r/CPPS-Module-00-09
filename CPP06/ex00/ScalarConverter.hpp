/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:43:29 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/02 18:36:36 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <climits>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter& operator=( const ScalarConverter& before );
		ScalarConverter( const ScalarConverter& before );
	public:
		static void convert(std::string const &str);

};

#endif
