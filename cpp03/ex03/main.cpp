/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:42:28 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/13 16:42:28 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

void testClapTrap() {
    std::cout << "\n=== Testing ClapTrap ===" << std::endl;
    
    ClapTrap clap("CT-1000");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
}

void testScavTrap() {
    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    
    ScavTrap scav("ST-1000");
    scav.attack("Target");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
}

void testFragTrap() {
    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    
    FragTrap frag("FT-1000");
    frag.attack("Target");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();
}

void testDiamondTrap() {
    std::cout << "\n=== Testing DiamondTrap ===" << std::endl;
    
    DiamondTrap diamond("DT-1000");
    diamond.attack("Target");
    diamond.takeDamage(50);
    diamond.beRepaired(25);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
}

int main() {
    testClapTrap();
    testScavTrap();
    testFragTrap();
    testDiamondTrap();
    return 0;
}