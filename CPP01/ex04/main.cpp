/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:07:14 by nmagro-r          #+#    #+#             */
/*   Updated: 2025/10/29 18:07:30 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>


int main(int argc, char **argv)
{
    
    if (argc != 4)
    {
        std::cout  << "invalid argument number" <<  std::endl;
        return(1);
    }
    if(argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cout << "type a valid string." << std::endl;
        return (1);
    }
    
    //args 
    std::string filename = argv[1];
    std::string outputFilename;
    std::string string1 = argv[2];
    std::string string2 = argv[3];
    
    //getline variables
    std::string line;
    std::string content = "";

    //replace

    std::string result = "";
    size_t startPos = 0;
    
    std::ifstream  inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "can`t open file" << std::endl;
        return(1);
    }
    while (std::getline(inputFile, line))
    {
        content += line; 
        content += '\n';       
    }
    inputFile.close();
    
    size_t foundPos = content.find(string1, startPos);
    while (foundPos != std::string::npos )
    {
        result += content.substr(startPos, (foundPos - startPos));
        result += string2;
        startPos = foundPos + string1.length();
        foundPos = content.find(string1, startPos);
    }
    result += content.substr(startPos);

    outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cout << "Error, could´t create output file." << std::endl;
        return(1);
    }
    outputFile << result;
    outputFile.close();
    return(0);
}
