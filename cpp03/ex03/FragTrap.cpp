/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:18 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/13 16:29:18 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}


FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    std::cout << "FragTrap " << name << " copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}