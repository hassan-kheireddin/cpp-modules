ls
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <utility>
#include <climits>
#include <iomanip>
#include <set>
#include <string>

class PmergeME
{
private:
    std::vector<int> vecData;
    std::deque<int> deqData;
    std::vector<int> orgData;
    
    // Performance tracking
    size_t vecOp;
    size_t deqOp;
    clock_t _vectorStartTime;
    clock_t _vectorEndTime;
    clock_t _dequeStartTime;
    clock_t _dequeEndTime;
    
    // Input validation methods
    void _validateArguments(char** argv);
    std::vector<int> _parseArguments(char** argv);
    void _checkNumber(const std::string& numberStr);
    bool _isValidInteger(const std::string& str);
    
    // Jacobsthal number generation
    int _generateJacobsthal(int n);
    
    // Template Ford-Johnson algorithm methods
    template<typename Container>
    Container _mergeSortRecursive(Container& input, bool isVector);
    
    template<typename Container>
    void _insertionSort(Container& main, Container& pend, bool isVector);
    
    template<typename Container>
    Container _generateJacobsthalIndices(size_t size);
    
    template<typename Container>
    void _processJacobsthalIndices(Container& jacob, const Container& pend);
    
    template<typename Container>
    void _insertPendElements(Container& main, const Container& pend, const Container& jacob, bool isVector);
    
    template<typename Container>
    int _binarySearch(const Container& main, int target, int high, bool isVector);
    
    template<typename Container>
    void _setupPairs(Container& main, Container& pend, const Container& input, bool& hasOdd, bool isVector);
    
    template<typename Container>
    void _reconstructPendFromMain(Container& newPend, const Container& newMain, 
                                 const Container& main, const Container& pend);
    
    // Template performance tracking methods
    template<typename Container>
    void _startTiming(bool isVector);
    
    template<typename Container>
    void _stopTiming(bool isVector);
    
    template<typename Container>
    void _incrementOperations(bool isVector);
    
    template<typename Container>
    double _getElapsedTime(bool isVector) const;
    
    template<typename Container>
    const Container& _getData(bool isVector) const;
    
    template<typename Container>
    size_t _getOperationCount(bool isVector) const;
    
    // Performance tracking methods
    void _resetPerformanceTracking();
    
    // Output formatting methods
    void _printBefore() const;
    void _printAfter() const;
    void _printTimingResults() const;
    void _printOperationCount() const;

public:
    // Orthodox Canonical Form
    PmergeME();
    PmergeME(const PmergeME& other);
    PmergeME& operator=(const PmergeME& other);
    ~PmergeME();
    
    // Main interface
    void processInput(char** argv);
    void sortAndDisplay();
    
    // Getters
    const std::vector<int>& getVectorData() const;
    const std::deque<int>& getDequeData() const;
    size_t getVectorOperationCount() const;
    size_t getDequeOperationCount() const;
};

// Include template implementation
#include "PmergeME.tpp"

#endif // PMERGEME_HPP