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

// Forward declarations
class InputValidator;
class PerformanceTracker;

/**
 * @brief Template-based Ford-Johnson merge-insertion sort implementation
 * 
 * This class provides a scalable, container-agnostic implementation of the
 * Ford-Johnson merge-insertion sort algorithm. It can work with any STL
 * container that supports the required operations.
 */
template <typename Container>
class PmergeMe
{
public:
    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;
    typedef typename Container::size_type size_type;

private:
    PerformanceTracker* tracker;
    Container data;

    // Core algorithm methods
    Container mergeSortRecursive(Container& input);
    void insertionSort(Container& main, Container& pend);
    Container generateJacobsthalIndices(size_type size);
    void processJacobsthalIndices(Container& jacob, const Container& pend);
    void insertPendElements(Container& main, const Container& pend, const Container& jacob);
    int binarySearch(const Container& main, value_type target, int high);
    
    // Utility methods
    void setupPairs(Container& main, Container& pend, const Container& input, bool& hasOdd);
    void reconstructPendFromMain(Container& newPend, const Container& newMain, 
                                const Container& main, const Container& pend);

public:
    // Constructors and destructor
    PmergeMe();
    explicit PmergeMe(PerformanceTracker* perfTracker);
    ~PmergeMe();

    // Main interface
    Container sort(const Container& input);
    void parseAndSort(char** argv);
    
    // Getters
    const Container& getData() const;
    size_type getOperationCount() const;
};

/**
 * @brief Validates input arguments and converts them to integers
 */
class InputValidator
{
public:
    static void validateArguments(char** argv);
    static std::vector<int> parseArguments(char** argv);
    
private:
    static void checkNumber(const std::string& numberStr);
    static bool isValidInteger(const std::string& str);
};

/**
 * @brief Tracks performance metrics during sorting operations
 */
class PerformanceTracker
{
private:
    size_t operationCount;
    clock_t startTime;
    clock_t endTime;

public:
    PerformanceTracker();
    
    void reset();
    void startTiming();
    void stopTiming();
    void incrementOperations();
    
    size_t getOperationCount() const;
    double getElapsedTime() const;
};

/**
 * @brief Utility class for Jacobsthal number generation
 */
class JacobsthalGenerator
{
public:
    static int generate(int n);
};

/**
 * @brief Output formatter for displaying results
 */
class ResultFormatter
{
public:
    template <typename Container1, typename Container2>
    static void printContainers(const Container1& vec, const Container2& deq);
    
    static void printTimingResults(size_t size, double time, const std::string& containerName);
    static void printOperationCount(size_t count, const std::string& containerName);
    static void printBefore(const std::vector<int>& data);
};

// Include template implementation
#include "PmergeMe.tpp"

#endif // PMERGEME_HPP