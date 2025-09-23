#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
        return 1;
    }
    
    try {
        // Parse and validate input
        std::vector<int> inputNumbers = InputValidator::parseArguments(argv);
        
        // Display input
        ResultFormatter::printBefore(inputNumbers);
        
        // Setup performance trackers
        PerformanceTracker vectorTracker;
        PerformanceTracker dequeTracker;
        
        // Create sorter instances
        PmergeMe<std::vector<int> > vectorSorter(&vectorTracker);
        PmergeMe<std::deque<int> > dequeSorter(&dequeTracker);
        
        // Convert input to containers
        std::vector<int> vectorData(inputNumbers.begin(), inputNumbers.end());
        std::deque<int> dequeData(inputNumbers.begin(), inputNumbers.end());
        
        // Perform sorting with timing
        std::vector<int> sortedVector = vectorSorter.sort(vectorData);
        std::deque<int> sortedDeque = dequeSorter.sort(dequeData);
        
        // Display results
        ResultFormatter::printContainers(sortedVector, sortedDeque);
        
        // Display timing information
        ResultFormatter::printTimingResults(sortedDeque.size(), dequeTracker.getElapsedTime(), "std::deque");
        ResultFormatter::printTimingResults(sortedVector.size(), vectorTracker.getElapsedTime(), "std::vector");
        
        // Display operation counts
        ResultFormatter::printOperationCount(vectorTracker.getOperationCount(), "vector");
        ResultFormatter::printOperationCount(dequeTracker.getOperationCount(), "deque");
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}