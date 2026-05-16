/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:19:55 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/28 22:20:00 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cerr << "Error Args" << std::endl, 1);
    if (!av[1] || !av[2] || !av[3])
        return (std::cerr << "Invalid Args" << std::endl, 1);
    std::string file;
    file = av[1];
    std::ifstream input_file (file.c_str());
    if (!input_file)
        return (std::cerr << "Failed to open file" << std::endl, 1);
    std::string s1;
    std::string s2;
    std::string line;
    std::string res;
    std::string cont;
    size_t         i;
    size_t         found;
    file = file + ".replace";
    s1 = av[2];
    s2 = av[3];
    if (s1.length() == 0)
        return (std::cerr << "Invalid string to find" << std::endl, 1);
    i = 0;
    found = 0;
    while (std::getline(input_file, line))
        cont += line + "\n";
    while ((found = cont.find(s1, i)) != std::string::npos)
    {
        res += cont.substr(i, found - i);
        res += s2;
        i = found + s1.length();
    }
    res += cont.substr(i);
    std::ofstream output_file(file.c_str());
    if (!output_file.is_open())
        return (std::cerr << "Error: output file" << std::endl, 1);
    output_file << res;
    return (0);
}
