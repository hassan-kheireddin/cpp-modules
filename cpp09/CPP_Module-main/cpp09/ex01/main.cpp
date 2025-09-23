#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Wrong input" << std::endl;
        return 1;
    }
    try
    {
        int result = RPN::calculate(av[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return (0);
}