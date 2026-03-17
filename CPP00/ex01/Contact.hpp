/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:55:42 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/20 15:55:44 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

class Contact
{
    public:
        Contact();
        ~Contact();
        
        void setName(const std::string &name);
        void setLast(const std::string &last);
        void setNick(const std::string &nick);
        void setPhone(const std::string &phone);
        void setSecret(const std::string &secret);

        std::string getName() const;
        std::string getLast() const;
        std::string getNick() const;
        std::string getPhone() const;
        std::string getSecret() const;

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
};

#endif
