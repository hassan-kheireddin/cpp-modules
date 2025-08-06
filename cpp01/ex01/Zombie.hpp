/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:34:57 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 12:34:57 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(); //It is important when creating an array of Zombies, the default constructor is called for each element.
    void setName(std::string name); //It avoids passing the name directly to the constructor during bulk allocation (which isn’t straightforward with new Zombie[N]).
    ~Zombie();
    void announce() const;

};

Zombie* zombieHorde(int N, std::string name);

#endif