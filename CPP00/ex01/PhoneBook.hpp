/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:55:26 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/20 15:55:29 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>
# include <unistd.h>

class PhoneBook
{
    public: 
        PhoneBook();
        ~PhoneBook();
        
        void add();
        void search();

    private:
        Contact contacts[8];
        int total_contacts;
        int oldest_contact;
};

#endif