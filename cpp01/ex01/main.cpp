/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:34:07 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/08 12:34:07 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
        int N = 3;
    std::string name = "HordeZombie";
    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }
    delete[] horde; // Free the memory allocated for the horde of zombies
    return 0;
}