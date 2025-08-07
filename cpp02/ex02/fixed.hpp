/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:01:47 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 19:01:47 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int rawValue;
    static const int fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);


    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif