/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:06:40 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/13 10:06:40 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    // Test construction/destruction order
    std::cout << "\n=== Testing FragTrap Construction/Destruction ===" << std::endl;
    {
        FragTrap frag("Boomer");
    }

    // Test functionality
    std::cout << "\n=== Testing FragTrap Functionality ===" << std::endl;
    FragTrap frag("Exploder");
    frag.attack("Target");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

    return 0;
}