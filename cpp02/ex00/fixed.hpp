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

class Fixed {
private:
    int rawValue;
    static const int fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed& other); //Creates a new object as a copy of another Fixed object
    Fixed& operator=(const Fixed& other); // Assigns the value of one Fixed object to another.
    ~Fixed();


    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif