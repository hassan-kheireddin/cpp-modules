#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, float> data;
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
    float getExchangeRate(const std::string& date) const;
    void trim(std::string& str) const;
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void loadDatabase(const std::string& filename = "data.csv");
    void processInput(const std::string& filename) const;
};

#endif