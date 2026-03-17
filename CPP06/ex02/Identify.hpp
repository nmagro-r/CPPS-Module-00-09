/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:30:22 by nmagro-r          #+#    #+#             */
/*   Updated: 2026/02/04 13:17:38 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include <typeinfo>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif