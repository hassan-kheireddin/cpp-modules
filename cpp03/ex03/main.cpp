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

int main() {
    // Test construction/destruction
    DiamondTrap diamond("Gem");
    
    // These now work without ambiguity
    diamond.takeDamage(30);
    diamond.beRepaired(10);
    
    // Polymorphism now works
    ClapTrap* clap = new DiamondTrap("Poly");
    clap->attack("Enemy");
    delete clap;
    
    return 0;
}