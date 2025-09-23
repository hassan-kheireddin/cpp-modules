#include "PmergeMe.hpp"

// InputValidator implementation
void InputValidator::validateArguments(char** argv)
{
    if (argv[1] == NULL) {
        throw std::invalid_argument("Error: No input provided.");
    }
    
    std::set<int> seenNumbers;
    int numberCount = 0;
    
    for (int i = 1; argv[i]; i++) {
        std::string arg = argv[i];
        std::stringstream ss(arg);
        std::string number;
        
        while (std::getline(ss, number, ' ')) {
            if (number.empty()) continue;
            
            checkNumber(number);
            
            long num = std::atol(number.c_str());
            if (num < INT_MIN || num > INT_MAX) {
                throw std::invalid_argument("Error: Number is out of range (must be between " + 
                                          std::string("INT_MIN") + " and " + std::string("INT_MAX") + ").");
            }
            
            seenNumbers.insert(static_cast<int>(num));
            numberCount++;
        }
    }
    
    if (numberCount < 2) {
        throw std::invalid_argument("Error: At least two numbers are required.");
    }
}

std::vector<int> InputValidator::parseArguments(char** argv)
{
    validateArguments(argv);
    
    std::vector<int> numbers;
    
    for (int i = 1; argv[i]; i++) {
        std::string arg = argv[i];
        std::stringstream ss(arg);
        std::string number;
        
        while (std::getline(ss, number, ' ')) {
            if (number.empty()) continue;
            numbers.push_back(std::atoi(number.c_str()));
        }
    }
    
    return numbers;
}

void InputValidator::checkNumber(const std::string& numberStr)
{
    if (!isValidInteger(numberStr)) {
        throw std::invalid_argument("Error: Input contains non-numeric characters.");
    }
    
    if (numberStr == "-") {
        throw std::invalid_argument("Error: Invalid number format '-'. Expected a valid integer.");
    }
}

bool InputValidator::isValidInteger(const std::string& str)
{
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str.length() == 1) return false;
        start = 1;
    }
    
    for (size_t i = start; i < str.length(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    
    return true;
}

// PerformanceTracker implementation
PerformanceTracker::PerformanceTracker() : operationCount(0), startTime(0), endTime(0) {}

void PerformanceTracker::reset()
{
    operationCount = 0;
    startTime = 0;
    endTime = 0;
}

void PerformanceTracker::startTiming()
{
    startTime = clock();
}

void PerformanceTracker::stopTiming()
{
    endTime = clock();
}

void PerformanceTracker::incrementOperations()
{
    operationCount++;
}

size_t PerformanceTracker::getOperationCount() const
{
    return operationCount;
}

double PerformanceTracker::getElapsedTime() const
{
    if (startTime == 0 || endTime == 0) return 0.0;
    return static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
}

// JacobsthalGenerator implementation
int JacobsthalGenerator::generate(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// ResultFormatter implementation
void ResultFormatter::printTimingResults(size_t size, double time, const std::string& containerName)
{
    std::cout << "Time to process a range of " << size << " elements with " << containerName << ": ";
    std::cout << std::fixed << std::setprecision(6) << time << " us" << std::endl;
}

void ResultFormatter::printOperationCount(size_t count, const std::string& containerName)
{
    std::cout << "Total moves for " << containerName << "-based sorting: " << count << std::endl;
}

void ResultFormatter::printBefore(const std::vector<int>& data)
{
    std::cout << "before:         ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i < data.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}