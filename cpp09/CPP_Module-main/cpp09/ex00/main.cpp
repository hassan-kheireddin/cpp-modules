#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange exchange("data.csv");
        exchange.processInputFile(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
