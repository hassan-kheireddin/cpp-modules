/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:09:48 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/11 16:09:48 by hkheired         ###   ########.fr       */
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
    delete clap;

    return 0;
}