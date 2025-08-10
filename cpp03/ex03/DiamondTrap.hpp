#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    // Resolve the attack() ambiguity by providing our own implementation
    void attack(const std::string& target);
    // Resolve ambiguity by explicitly declaring these
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    void whoAmI() const;
};

#endif