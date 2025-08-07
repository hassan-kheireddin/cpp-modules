/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:01:40 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 19:01:40 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : rawValue(value << fractionalBits) //Shifts the integer left by fractionalBits to store it as a fixed-point value.
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawValue(roundf(value * (1 << fractionalBits))) //Multiplies the float by 2^fractionalBits and rounds it to the nearest integer
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->rawValue = raw;
}

float Fixed::toFloat() const //Divides or shifts the rawValue to reverse the conversion
{
    return static_cast<float>(rawValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return rawValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) //Allows printing a Fixed object using std::cout
{
    os << fixed.toFloat();
    return os;
}