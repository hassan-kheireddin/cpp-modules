#include "PmergeMe.hpp"

// parsing and checking for errors

void    check_numbers(char **av)
{
    if (av[1] == NULL)
        throw std::invalid_argument("Error: No input provided.");
    std::set<int> seenNumbers;
    int numberCount = 0;

    for (int i = 1; av[i]; i++)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        std::string number;
        while (std::getline(ss, number, ' '))
        {
            if (number.empty())
                continue;
            for (size_t j = 0; j < number.size(); j++)
            {
                if (!isdigit(number[j]) && !(j == 0 && number[j] == '-'))
                    throw std::invalid_argument("Error: Input contains non-numeric characters.");
            }
            if (number == "-")
                throw std::invalid_argument("Error: Invalid number format '-'. Expected a valid integer.");
            long num = std::atol(number.c_str());
            // if (num < 0)
            //     throw std::invalid_argument("Error: Numbers should be positive.");
            if (num < INT_MIN || num > INT_MAX)
                throw std::invalid_argument("Error: Number is out of range (must be between 0 and 2147483647).");
            // if (seenNumbers.find(num) != seenNumbers.end())
            //     throw std::invalid_argument("Error: Duplicate number found: " + number);
            seenNumbers.insert(num);
            numberCount++;
        }
    }
    if (numberCount < 2)
        throw std::invalid_argument("Error: At least two numbers are required.");
}



int Jacobthal_number_generator(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
