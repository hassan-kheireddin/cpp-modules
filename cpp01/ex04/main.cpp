/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:58:40 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 16:58:40 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& line, const std::string& s1, const std::string& s2) {
    if (s1.empty()) return line;
    std::string result;
    result.reserve(line.length());
    size_t pos = 0;
    size_t prev_pos = 0;

    while ((pos = line.find(s1, pos)) != std::string::npos)//npos is a special constant indicate imposible to find the substring
    {
        result.append(line, prev_pos, pos - prev_pos);
        result.append(s2);
        pos += s1.length();
        prev_pos = pos;
    }
    result.append(line, prev_pos, line.length() - prev_pos);
    return result;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Could not open file '" << argv[1] << "'\n";
        return 1;
    }

    std::ofstream outputFile((std::string(argv[1]) + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Could not create output file\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, argv[2], argv[3]) << '\n';
    }

    std::cout << "Replacement complete. Output written to '" 
              << argv[1] << ".replace'\n";
    return 0;
}