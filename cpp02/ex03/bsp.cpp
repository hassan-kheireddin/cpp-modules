/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:42:28 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/09 19:42:28 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
//Used to determine the orientation of the point relative to the triangle edges.
static Fixed crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    Fixed x1 = p2.getX() - p1.getX();
    Fixed y1 = p3.getY() - p1.getY();
    Fixed x2 = p2.getY() - p1.getY();
    Fixed y2 = p3.getX() - p1.getX();
    
    return (x1 * y1) - (x2 * y2);
}
//uses the cross product to check the point’s position relative to each edge.
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed zero(0);
    Fixed d1 = crossProduct(point, a, b);
    Fixed d2 = crossProduct(point, b, c);
    Fixed d3 = crossProduct(point, c, a);

    bool has_neg = (d1 < zero) || (d2 < zero) || (d3 < zero);
    bool has_pos = (d1 > zero) || (d2 > zero) || (d3 > zero);

    return !(has_neg && has_pos) && (d1 != zero && d2 != zero && d3 != zero);
}