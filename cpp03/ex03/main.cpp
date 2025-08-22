/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:05:22 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/13 10:05:22 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
    testDiamondTrap();
    return 0;
}
