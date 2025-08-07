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

Fixed::Fixed(const int value) : rawValue(value << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawValue(roundf(value * (1 << fractionalBits))) {
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

bool Fixed::operator==(const Fixed& other) const {
    return this->rawValue == other.rawValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->rawValue != other.rawValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->rawValue < other.rawValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->rawValue <= other.rawValue;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->rawValue > other.rawValue;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->rawValue >= other.rawValue;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->rawValue + other.rawValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->rawValue - other.rawValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->rawValue * other.rawValue) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.rawValue == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result.setRawBits((this->rawValue << fractionalBits) / other.rawValue);
    return result;
}

Fixed& Fixed::operator++() {
    this->rawValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->rawValue++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->rawValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->rawValue--;
    return temp;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->rawValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(rawValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return rawValue >> fractionalBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}