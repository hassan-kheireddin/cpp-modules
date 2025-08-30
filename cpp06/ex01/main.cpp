#include "Serializer.hpp"

int main()
{
	Data original;
	original.value = 42;
	original.name = "Answer";

	std::cout << "Original: " << original.value << ", " << original.name << std::endl;
	std::cout << "Original address: " << &original << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored address: " << restored << std::endl;
	std::cout << "Restored: " << restored->value << ", " << restored->name << std::endl;

	if (restored == &original)
		std::cout << "Pointers are equal! Serialization successful." << std::endl;
	else
		std::cout << "Error: Pointers are not equal." << std::endl;

	return 0;
}