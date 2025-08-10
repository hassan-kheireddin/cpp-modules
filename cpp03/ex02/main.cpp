/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:36:12 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 21:36:12 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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

    // Test polymorphism
    std::cout << "\n=== Testing Polymorphism ===" << std::endl;
    ClapTrap* clap = new FragTrap("Polymorph");
    clap->attack("Enemy");
    delete clap;

    std::cout << "\n=== Testing Copy/Assignment ===" << std::endl;
    FragTrap original("Original");
    FragTrap copy(original);
    FragTrap assigned;
    assigned = original;

    return 0;
}