#include "PmergeME.hpp"

// Orthodox Canonical Form implementation
PmergeME::PmergeME() : vecOp(0), deqOp(0), 
                       _vectorStartTime(0), _vectorEndTime(0), _dequeStartTime(0), _dequeEndTime(0) {}

PmergeME::PmergeME(const PmergeME& other) 
    : vecData(other.vecData), deqData(other.deqData), orgData(other.orgData),
      vecOp(other.vecOp), deqOp(other.deqOp),
      _vectorStartTime(other._vectorStartTime), _vectorEndTime(other._vectorEndTime),
      _dequeStartTime(other._dequeStartTime), _dequeEndTime(other._dequeEndTime) {}

PmergeME& PmergeME::operator=(const PmergeME& other)
{
    if (this != &other) {
        vecData = other.vecData;
        deqData = other.deqData;
        orgData = other.orgData;
        vecOp = other.vecOp;
        deqOp = other.deqOp;
        _vectorStartTime = other._vectorStartTime;
        _vectorEndTime = other._vectorEndTime;
        _dequeStartTime = other._dequeStartTime;
        _dequeEndTime = other._dequeEndTime;
    }
    return *this;
}

PmergeME::~PmergeME() {}

// Main interface implementation
void PmergeME::processInput(char** argv)
{
    orgData = _parseArguments(argv);
    vecData = std::vector<int>(orgData.begin(), orgData.end());
    deqData = std::deque<int>(orgData.begin(), orgData.end());
}

void PmergeME::sortAndDisplay()
{
    _printBefore();
    
    _resetPerformanceTracking();
    
    // Sort vector
    _startTiming<std::vector<int> >(true);
    vecData = _mergeSortRecursive(vecData, true);
    _stopTiming<std::vector<int> >(true);
    
    // Sort deque
    _startTiming<std::deque<int> >(false);
    deqData = _mergeSortRecursive(deqData, false);
    _stopTiming<std::deque<int> >(false);
    
    _printAfter();
    _printTimingResults();
    _printOperationCount();
}

// Input validation implementation
void PmergeME::_validateArguments(char** argv)
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
            
            _checkNumber(number);
            
            long num = std::atol(number.c_str());
            if (num < INT_MIN || num > INT_MAX) {
                throw std::invalid_argument("Error: Number is out of range (must be between INT_MIN and INT_MAX).");
            }
            
            seenNumbers.insert(static_cast<int>(num));
            numberCount++;
        }
    }
    
    if (numberCount < 2) {
        throw std::invalid_argument("Error: At least two numbers are required.");
    }
}

std::vector<int> PmergeME::_parseArguments(char** argv)
{
    _validateArguments(argv);
    
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

void PmergeME::_checkNumber(const std::string& numberStr)
{
    if (!_isValidInteger(numberStr)) {
        throw std::invalid_argument("Error: Input contains non-numeric characters.");
    }
    
    if (numberStr == "-") {
        throw std::invalid_argument("Error: Invalid number format '-'. Expected a valid integer.");
    }
}

bool PmergeME::_isValidInteger(const std::string& str)
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

// Jacobsthal number generation
int PmergeME::_generateJacobsthal(int n)
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

// Performance tracking methods
void PmergeME::_resetPerformanceTracking()
{
    vecOp = 0;
    deqOp = 0;
    _vectorStartTime = 0;
    _vectorEndTime = 0;
    _dequeStartTime = 0;
    _dequeEndTime = 0;
}



// Output formatting methods
void PmergeME::_printBefore() const
{
    std::cout << "before:         ";
    for (size_t i = 0; i < orgData.size(); ++i) {
        std::cout << orgData[i];
        if (i < orgData.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeME::_printAfter() const
{
    std::cout << "After vector:   ";
    for (size_t i = 0; i < vecData.size(); ++i) {
        std::cout << vecData[i];
        if (i < vecData.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "After deque:    ";
    for (size_t i = 0; i < deqData.size(); ++i) {
        std::cout << deqData[i];
        if (i < deqData.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeME::_printTimingResults() const
{
    std::cout << "Time to process a range of " << deqData.size() << " elements with std::deque: ";
    std::cout << std::fixed << std::setprecision(6) << _getElapsedTime<std::deque<int> >(false) << " us" << std::endl;
    
    std::cout << "Time to process a range of " << vecData.size() << " elements with std::vector: ";
    std::cout << std::fixed << std::setprecision(6) << _getElapsedTime<std::vector<int> >(true) << " us" << std::endl;
}

void PmergeME::_printOperationCount() const
{
    std::cout << "Total moves for vector-based sorting: " << _getOperationCount<std::vector<int> >(true) << std::endl;
    std::cout << "Total moves for deque-based sorting: " << _getOperationCount<std::deque<int> >(false) << std::endl;
}

// Getters
const std::vector<int>& PmergeME::getVectorData() const
{
    return _getData<std::vector<int> >(true);
}

const std::deque<int>& PmergeME::getDequeData() const
{
    return _getData<std::deque<int> >(false);
}

size_t PmergeME::getVectorOperationCount() const
{
    return _getOperationCount<std::vector<int> >(true);
}

size_t PmergeME::getDequeOperationCount() const
{
    return _getOperationCount<std::deque<int> >(false);
}