/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:49:23 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/30 16:49:51 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP


#include <iostream>
#include <string>

class Harl
{
  public:
    Harl
  
();
    ~Harl
  
();
    void complain(std::string level);
    
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};
#endif