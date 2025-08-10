/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:25:42 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 21:25:42 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // Test construction/destruction order
    std::cout << "\n=== Testing Construction/Destruction ===" << std::endl;
    {
        ScavTrap scav("Guardian");
    }

    // Test functionality
    std::cout << "\n=== Testing Functionality ===" << std::endl;
    ScavTrap scav("Protector");
    ClapTrap* clap = new ScavTrap("Polymorph");

    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    // Test polymorphism
    std::cout << "\n=== Testing Polymorphism ===" << std::endl;
    clap->attack("Target");  // Should use ScavTrap's attack
    delete clap;

    // Test copy and assignment
    std::cout << "\n=== Testing Copy/Assignment ===" << std::endl;
    ScavTrap original("Original");
    ScavTrap copy(original);
    ScavTrap assigned;
    assigned = original;

    return 0;
}