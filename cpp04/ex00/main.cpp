/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:06:29 by hkheired          #+#    #+#             */
/*   Updated: 2025/07/13 22:06:29 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimalSound(const Animal& animal) {
    std::cout << "Type: " << animal.getType() << std::endl;
    animal.makeSound();
}

void testWrongAnimalSound(const WrongAnimal& animal) {
    std::cout << "Type: " << animal.getType() << std::endl;
    animal.makeSound();
}

int main() {
    std::cout << "===== BASIC TESTS =====" << std::endl << std::endl;
    {
        Animal animal;
        Dog dog;
        Cat cat;
        
        testAnimalSound(animal);
        testAnimalSound(dog);
        testAnimalSound(cat);
    }
    
    std::cout << "\n===== COPY TESTS =====" << std::endl << std::endl;
    {
        Dog originalDog;
        Dog copiedDog(originalDog);
        testAnimalSound(copiedDog);
        
        Cat originalCat;
        Cat assignedCat;
        assignedCat = originalCat;
        testAnimalSound(assignedCat);
    }
    
    std::cout << "\n===== WRONG ANIMAL TESTS =====" << std::endl << std::endl;
    {
        WrongAnimal wrongAnimal;
        WrongCat wrongCat;
        
        testWrongAnimalSound(wrongAnimal);
        testWrongAnimalSound(wrongCat);
    }

    std::cout << "\n===== POLYMORPHISM TESTS =====" << std::endl << std::endl;
    {
        Animal* animals[4];
        
        animals[0] = new Animal();
        animals[1] = new Dog();
        animals[2] = new Cat();
        animals[3] = new Dog();
        
        for (int i = 0; i < 4; i++) {
            testAnimalSound(*animals[i]);
            delete animals[i];
        }
    }

    std::cout << "\n===== WRONG POLYMORPHISM TESTS =====" << std::endl << std::endl;
    {
        WrongAnimal* wrongAnimals[2];
        
        wrongAnimals[0] = new WrongAnimal();
        wrongAnimals[1] = new WrongCat();
        
        for (int i = 0; i < 2; i++) {
            testWrongAnimalSound(*wrongAnimals[i]);
            delete wrongAnimals[i];
        }
    }
    
    return 0;
}