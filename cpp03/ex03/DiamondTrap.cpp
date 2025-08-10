/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:39:13 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 21:39:13 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
    name = "Default";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    *this = other;
    std::cout << "DiamondTrap " << this->name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap " << this->name << " copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI() const {
    std::cout << "I am DiamondTrap " << this->name
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}