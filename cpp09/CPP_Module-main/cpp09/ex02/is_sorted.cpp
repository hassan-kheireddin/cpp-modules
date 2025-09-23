#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

bool isSortedAscending(const std::vector<int>& nums)
{
    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (nums[i] < nums[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Please provide numbers as command-line arguments." << std::endl;
        return 1;
    }

    std::vector<int> nums;
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        std::string number;

        while (ss >> number)
        {
            char* endptr;
            int num = std::strtol(number.c_str(), &endptr, 10);
            if (*endptr != '\0')
            {
                std::cout << "Error: Invalid input '" << number << "' detected." << std::endl;
                return 1;
            }
            nums.push_back(num);
        }
    }

    if (nums.empty())
    {
        std::cout << "Error: No valid numbers provided." << std::endl;
        return 1;
    }

    if (isSortedAscending(nums))
    {
        std::cout << "The numbers are sorted in ascending order." << std::endl;
    }
    else
    {
        std::cout << "The numbers are not sorted in ascending order." << std::endl;
    }

    return 0;
}
