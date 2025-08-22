/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:03:02 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/13 16:03:02 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main() {
    // Animal meta; // Error: Cannot instantiate abstract class
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    j->makeSound(); // Calls Dog's makeSound()
    i->makeSound(); // Calls Cat's makeSound()

    delete j;
    delete i;

    return 0;
}