/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:09:02 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 18:09:02 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main() {
    Harl harl;
    
    std::cout << "TESTING HARL'S COMPLAINTS:\n" << std::endl;
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i) {
        std::cout << "Testing level: " << levels[i] << std::endl;
        harl.complain(levels[i]);
        std::cout << std::endl;
    }

    std::cout << "Testing invalid level: \"MINOR\"" << std::endl;
    harl.complain("MINOR");
    std::cout << std::endl;
    
    std::cout << "Testing empty level: \"\"" << std::endl;
    harl.complain("");
    std::cout << std::endl;
    

    std::cout << "Testing lowercase level: \"debug\"" << std::endl;
    harl.complain("debug");
    std::cout << std::endl;
    
    return 0;
}