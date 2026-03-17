/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:42:18 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/11/04 16:42:51 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP



#include <iostream>
#include <cmath>


class Fixed
{
    public:
        Fixed();
        Fixed(const int intNumber);
        Fixed(const float floatNum);
        Fixed (const Fixed &copy); //copy constructor
        Fixed &operator=(const Fixed &copy);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void)const;
        int toInt(void)const;
        




    private:
        int fixedNumberValue;
        static const int fractional = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif