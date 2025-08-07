/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:18:02 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 21:18:02 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    // Test points
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    
    // Inside the triangle
    Point p1(1, 1);
    // On edge
    Point p2(5, 0);
    // On vertex
    Point p3(0, 0);
    // Outside
    Point p4(10, 10);
    
    std::cout << "Point (1,1) inside: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "Point (5,0) inside: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "Point (0,0) inside: " << bsp(a, b, c, p3) << std::endl;
    std::cout << "Point (10,10) inside: " << bsp(a, b, c, p4) << std::endl;
    
    return 0;
}