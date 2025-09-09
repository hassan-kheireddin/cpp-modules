#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== Testing MutantStack ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    int i = 0;
    while (it != ite)
    {
        std::cout << "Element " << i++ << ": " << *it << std::endl;
        ++it;
    }

    std::cout << "\n=== Testing with std::list (for comparison) ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();

    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;
    i = 0;
    while (lit != lite)
    {
        std::cout << "Element " << i++ << ": " << *lit << std::endl;
        ++lit;
    }

    return 0;
}