#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base* generate(void)
{
	std::srand(std::time(0));
	int random = std::rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "Generated: A" << std::endl;
			return new A;
		case 1:
			std::cout << "Generated: B" << std::endl;
			return new B;
		case 2:
			std::cout << "Generated: C" << std::endl;
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A (identified by pointer)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B (identified by pointer)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C (identified by pointer)" << std::endl;
	else
		std::cout << "Unknown type (pointer)" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A (identified by reference)" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B (identified by reference)" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C (identified by reference)" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "Unknown type (reference)" << std::endl;
}

int main()
{
	Base* basePtr = generate();
	identify(basePtr);
	identify(*basePtr);
	delete basePtr;
	return 0;
}