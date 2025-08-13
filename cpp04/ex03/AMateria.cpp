/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:14:11 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/15 20:14:11 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
    return type;
}