/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:08:03 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/15 19:08:03 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Animal meta; // Error: Cannot instantiate abstract class

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    j->makeSound(); // Calls Dog's makeSound()
    i->makeSound(); // Calls Cat's makeSound()

    delete j;
    delete i;

    return 0;
}