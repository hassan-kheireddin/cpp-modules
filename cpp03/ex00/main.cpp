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

int main() {
    // Test constructors
    ClapTrap defaultTrap;
    ClapTrap namedTrap("Robo");
    ClapTrap copyTrap(namedTrap);

    // Test assignment
    defaultTrap = namedTrap;

    // Test functionality
    namedTrap.attack("Enemy");
    namedTrap.takeDamage(5);
    namedTrap.beRepaired(3);
    namedTrap.takeDamage(10);  // Should destroy
    namedTrap.attack("Enemy"); // Should fail
    namedTrap.beRepaired(5);   // Should fail

    // Test energy points
    ClapTrap energyTester("Battery");
    for (int i = 0; i < 12; i++) {
        energyTester.attack("Target");
    }

    return 0;
}