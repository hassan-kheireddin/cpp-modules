/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:54:37 by hkheired          #+#    #+#             */
/*   Updated: 2025/08/13 15:54:37 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Create an array of Animal pointers
    const int size = 4;
    Animal* animals[size];

    // Fill the array with Dogs and Cats
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Test deep copy
    Dog dog1;
    dog1.makeSound();
    Dog dog2 = dog1; // Calls copy constructor
    dog2.makeSound();

    Cat cat1;
    cat1.makeSound();
    Cat cat2 = cat1; // Calls copy constructor
    cat2.makeSound();

    // Clean up
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    return 0;
}