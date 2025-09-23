#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other):exchangeRates(other.exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \n\r\t");
    size_t end = str.find_last_not_of(" \n\r\t");

    if (start == std::string::npos || end == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

// Open the files and take the data from it

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        line = trim(line);
        std::stringstream ss(line);
        std::string date, rateStr;
        double rate;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
        {
            rate = atof(rateStr.c_str());
            rateStr = trim(rateStr);
            if (!isValidDate(date))
            {
                std::cerr << "Error: invalid date => " << date << std::endl;
                continue;
            }
            if (rateStr.find_first_not_of("0123456789.-") != std::string::npos || rateStr.empty()) //npos means that it reaches the \0
            {
                std::cerr << "Error: invalid rate value => " << rateStr << " for date: " << date << std::endl;
                continue;
            }
            try
            {
                rate = atof(rateStr.c_str()); 
                if (rate < 0)
                {
                    std::cerr << "Error: negative rate value => " << rate << " for date: " << date << std::endl;
                    continue;
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error: invalid rate value => " << rateStr << " for date: " << date << std::endl;
                continue;
            }
            exchangeRates[date] = rate;
        }
        else
        {
            std::cerr << "Error: bad line format in database file => " << line << std::endl;
        }
    }
}

// Get the date from the data.csv

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first > date)
    {
        if (it == exchangeRates.begin())
            throw std::runtime_error("Error: no earlier exchange rate available.");
        --it;
    }
    return it->second;
}

bool one_point(std::string value)
{
    int dotCount = 0;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
            dotCount++;
        else if (!isdigit(value[i]))
            return false;
    }
    if (dotCount > 1)
        throw std::invalid_argument("Error: more than one dot in input.");
    if (value.size() > 0 && value[value.size() - 1] == '.')
        throw std::invalid_argument("Error: input cannot end with a dot.");
    return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) const
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");
    std::string line;
    std::getline(file, line);
    line = trim(line);
    if ( line != "date | value")
        throw std::runtime_error("Error: its not \"date | value\"");
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue;
        std::stringstream ss(line); // This copies the line content into ss
        std::string date, valueStr; // The first getline takes everything before the "|" and removes the "|" from ss
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date = trim(date);
            valueStr = trim(valueStr);
            if (!isValidDate(date))
            {
                std::cerr << "Error: invalid date => " << date << std::endl;
                continue;
            }
            try
            {
                if (one_point(valueStr))
                {
                    if (valueStr.find_first_not_of("0123456789.") != std::string::npos || valueStr.empty())
                        throw std::invalid_argument("wrong input");
                    double value = atof(valueStr.c_str());
                    if (value < 0)
                        throw std::out_of_range("not a positive number.");
                    if (value > 1000)
                        throw std::out_of_range("too large a number.");
                    double rate = getExchangeRate(date);
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                }
                else
                {
                    throw std::invalid_argument("wrong input");
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}


// Check the date if its exeptable.

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && leapyear)
        return day <= 29;
    else
        return day <= daysInMonth[month - 1];
}
