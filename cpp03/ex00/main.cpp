/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:28:50 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 20:28:50 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    
    ClapTrap clap1("CT-1000");
    ClapTrap clap2("CT-2000");
    
    clap1.attack("CT-2000");
    clap2.takeDamage(5);
    
    clap2.attack("CT-1000");
    clap1.takeDamage(3);
    
    clap1.beRepaired(2);
    clap2.beRepaired(4);
    
    // Testing edge cases
    ClapTrap clap3("CT-3000");
    for (int i = 0; i < 12; i++) {
        clap3.attack("Target");
    }
    
    clap3.takeDamage(15);
    clap3.beRepaired(5);
    
    return 0;
}