#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Trim whitespace from string
void BitcoinExchange::trim(std::string& str) const {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start != std::string::npos) {
        str = str.substr(start);
    }
    
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (end != std::string::npos) {
        str = str.substr(0, end + 1);
    }
}


// Validate date format
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    
    // Extract year, month, day
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());
    
    // Basic validation
    if (year < 2000 || year > 2100) return false; // Reasonable range
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // Month-specific day validation
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }
    
    if (month == 2) {
        // Simple leap year check
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28)) return false;
    }
    
    return true;
}
















bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    
    if (valueStr.empty()) {
        std::cerr << "Error: empty value." << std::endl;
        return false;
    }
    
    bool hasDecimal = false;
    bool hasSign = false;
    for (size_t i = 0; i < valueStr.length(); i++) {
        if (i == 0 && valueStr[i] == '+') {
            hasSign = true;
            continue;
        }
        if (!std::isdigit(valueStr[i]) && valueStr[i] != '.') {
            std::cerr << "Error: not a valid number => " << valueStr << std::endl;
            return false;
        }
        if (valueStr[i] == '.') {
            if (hasDecimal) {
                std::cerr << "Error: not a valid number => " << valueStr << std::endl;
                return false;
            }
            hasDecimal = true;
        }
    }
    
    char* end;
    value = std::strtof(valueStr.c_str(), &end);
    
    if (end == valueStr.c_str() || *end != '\0') {
        std::cerr << "Error: not a valid number => " << valueStr << std::endl;
        return false;
    }
    
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}

























// Get exchange rate for given date
float BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (data.empty()) {
        throw std::runtime_error("Error: database is empty.");
    }

    std::map<std::string, float>::const_iterator it = data.find(date);
    if (it != data.end()) {
        return it->second;
    }
    
    it = data.lower_bound(date);//Returns an iterator pointing to the first element in the container whose key is greater than or equal (≥) to the given key
    
    if (it == data.begin()) {
        throw std::runtime_error("Error: no data available for date " + date + " or earlier.");
    }
    
    if (it == data.end()) {
        return data.rbegin()->second;
    }

    --it;
    return it->second;
}














// Process input file
// void BitcoinExchange::processInput(const std::string& filename) const {
//     std::ifstream file(filename.c_str());
//     if (!file.is_open()) {
//         throw std::runtime_error("Error: could not open file.");
//     }
    
//     std::string line;

//     if (!std::getline(file, line)) {
//         file.close();
//         throw std::runtime_error("Error: empty input file.");
//     }

//     if (line != "date | value") {
//         file.close();
//         throw std::runtime_error("Error: invalid input header. Expected 'date | value' but got '" + line + "'");
//     }
    
//     while (std::getline(file, line)) {
//         if (line.empty()) continue;
        
//         size_t pipePos = line.find('|');
//         if (pipePos == std::string::npos) {
//             std::cerr << "Error: bad input => " << line << std::endl;
//             continue;
//         }
        
//         std::string datePart = line.substr(0, pipePos);
//         std::string valuePart = line.substr(pipePos + 1);
        
//         trim(datePart);
//         trim(valuePart);
    
//         if (!isValidDate(datePart)) {
//             std::cerr << "Error: bad input => " << line << std::endl;
//             continue;
//         }

//         float value;
//         if (!isValidValue(valuePart, value)) {
//             continue;
//         }
        
//         try {
//             float exchangeRate = getExchangeRate(datePart);
//             float result = value * exchangeRate;
//             std::cout << datePart << " => " << value << " = " << result << std::endl;
//         } catch (const std::exception& e) {
//             std::cerr << e.what() << std::endl;
//         }
//     }
//     file.close();
// }

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    
    std::string line;
    // Read and validate header line
    if (!std::getline(file, line)) {
        file.close();
        throw std::runtime_error("Error: empty input file.");
    }
    
    // Trim the line before comparison to handle potential whitespace
    std::string trimmedLine = line;
    trim(trimmedLine);
    
    // Check if the header is exactly "date | value" (after trimming)
    if (trimmedLine != "date | value") {
        file.close();
        throw std::runtime_error("Error: invalid input header. Expected 'date | value' but got '" + line + "'");
    }
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string datePart = line.substr(0, pipePos);
        std::string valuePart = line.substr(pipePos + 1);
        
        trim(datePart);
        trim(valuePart);
        
        // Validate date
        if (!isValidDate(datePart)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Validate value
        float value;
        if (!isValidValue(valuePart, value)) {
            continue; // Error message already printed by isValidValue
        }
        
        try {
            float exchangeRate = getExchangeRate(datePart);
            float result = value * exchangeRate;
            std::cout << datePart << " => " << value << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    
    file.close();
}
























void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }
    
    std::string line;
    if (!std::getline(file, line)) {
        file.close();
        throw std::runtime_error("Error: empty database file.");
    }

    if (line != "date,exchange_rate") {
        file.close();
        throw std::runtime_error("Error: invalid database header. Expected 'date,exchange_rate' but got '" + line + "'");
    }
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        std::string date, rateStr;
        
        if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
            trim(date);
            trim(rateStr);
            
            if (!isValidDate(date)) {
                std::cerr << "Error: invalid date in database: " + date << std::endl;
                continue;
            }

            char* end;
            float rate = std::strtof(rateStr.c_str(), &end);

            if (end == rateStr.c_str() || *end != '\0') {
                std::cerr << "Warning: Invalid exchange rate format in database: " << line << std::endl;
                continue;
            }
            if (rate < 0) {
                std::cerr << "Warning: Negative exchange rate in database: " << line << std::endl;
                continue;
            }
            
            data[date] = rate;
        }
        else {
            std::cerr << "Error: invalid line format in database: " << line << std::endl;
        }
    }
    
    file.close();
    
    if (data.empty()) {
        throw std::runtime_error("Error: database is empty or invalid.");
    }
}