/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:55:04 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/15 18:55:04 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}