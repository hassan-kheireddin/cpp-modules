#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> exchangeRates;
        void loadDatabase(const std::string& filename);
        bool isValidDate(const std::string& date) const;

    public:
        BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& other);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        BitcoinExchange(const std::string& databaseFile);

        double getExchangeRate(const std::string& date) const;
        void processInputFile(const std::string& inputFile) const;
};

#endif
