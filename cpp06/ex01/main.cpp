#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;
    data.name = "Test Data";

    std::cout << "Original data: " << data.value << ", " << data.name << std::endl;
    std::cout << "Original address: " << &data << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized data: " << deserialized->value << ", " << deserialized->name << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;

    if (deserialized == &data) {
        std::cout << "Success: Original and deserialized pointers match!" << std::endl;
    } else {
        std::cout << "Error: Pointers don't match!" << std::endl;
    }

    return 0;
}