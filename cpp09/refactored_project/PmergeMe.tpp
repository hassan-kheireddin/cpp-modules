#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

// Template implementation for PmergeMe class

template <typename Container>
PmergeMe<Container>::PmergeMe() : tracker(0) {}

template <typename Container>
PmergeMe<Container>::PmergeMe(PerformanceTracker* perfTracker) : tracker(perfTracker) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
Container PmergeMe<Container>::sort(const Container& input)
{
    data = input;
    if (tracker) {
        tracker->reset();
        tracker->startTiming();
    }
    
    Container result = mergeSortRecursive(data);
    
    if (tracker) {
        tracker->stopTiming();
    }
    
    return result;
}

template <typename Container>
void PmergeMe<Container>::parseAndSort(char** argv)
{
    // Parse input arguments
    std::vector<int> numbers = InputValidator::parseArguments(argv);
    
    // Convert to target container type
    data.clear();
    for (size_t i = 0; i < numbers.size(); ++i) {
        data.push_back(numbers[i]);
    }
    
    // Perform sorting
    data = sort(data);
}

template <typename Container>
Container PmergeMe<Container>::mergeSortRecursive(Container& input)
{
    if (input.empty())
        return Container();
    
    if (input.size() == 1)
        return input;
    
    if (input.size() == 2) {
        Container result = input;
        if (tracker) tracker->incrementOperations();
        
        if (result[0] > result[1]) {
            std::swap(result[0], result[1]);
        }
        return result;
    }
    
    Container main, pend;
    bool hasOdd = false;
    
    // Setup pairs and determine odd element
    setupPairs(main, pend, input, hasOdd);
    
    // Recursively sort the main container
    Container newMain = mergeSortRecursive(main);
    
    // Reconstruct pend based on sorted main
    Container newPend;
    reconstructPendFromMain(newPend, newMain, main, pend);
    
    if (hasOdd) {
        newPend.push_back(input.back());
    }
    
    // Insert pend elements into main using Ford-Johnson algorithm
    insertionSort(newMain, newPend);
    
    return newMain;
}

template <typename Container>
void PmergeMe<Container>::setupPairs(Container& main, Container& pend, 
                                   const Container& input, bool& hasOdd)
{
    hasOdd = (input.size() % 2 == 1);
    iterator it = const_cast<Container&>(input).begin();
    
    while (it != const_cast<Container&>(input).end()) {
        if ((it + 1) == const_cast<Container&>(input).end()) {
            break;
        }
        
        if (tracker) tracker->incrementOperations();
        
        if (*it > *(it + 1)) {
            main.push_back(*it);
            pend.push_back(*(it + 1));
        } else {
            pend.push_back(*it);
            main.push_back(*(it + 1));
        }
        it += 2;
    }
}

template <typename Container>
void PmergeMe<Container>::reconstructPendFromMain(Container& newPend, const Container& newMain,
                                                const Container& main, const Container& pend)
{
    newPend.clear();
    newPend.resize(newMain.size());
    
    for (size_type i = 0; i < newMain.size(); ++i) {
        for (size_type j = 0; j < main.size(); ++j) {
            if (main[j] == newMain[i]) {
                newPend[i] = pend[j];
                break;
            }
        }
    }
}

template <typename Container>
void PmergeMe<Container>::insertionSort(Container& main, Container& pend)
{
    if (pend.empty()) return;
    
    Container jacob = generateJacobsthalIndices(pend.size());
    processJacobsthalIndices(jacob, pend);
    insertPendElements(main, pend, jacob);
}

template <typename Container>
Container PmergeMe<Container>::generateJacobsthalIndices(size_type size)
{
    Container jacobSequence;
    int jacobIndex = 3;
    
    while (JacobsthalGenerator::generate(jacobIndex) <= static_cast<int>(size)) {
        jacobSequence.push_back(JacobsthalGenerator::generate(jacobIndex));
        jacobIndex++;
    }
    
    return jacobSequence;
}

template <typename Container>
void PmergeMe<Container>::processJacobsthalIndices(Container& jacob, const Container& pend)
{
    typename Container::iterator it = jacob.begin();
    Container pushedNumbers;
    Container temp;
    
    while (it != jacob.end()) {
        int x;
        if (*it >= 0) {
            x = *it;
            while (x > 1) {
                if (std::find(pushedNumbers.begin(), pushedNumbers.end(), x) == pushedNumbers.end()) {
                    temp.push_back(x);
                    pushedNumbers.push_back(x);
                } else {
                    break;
                }
                x--;
            }
        }
        it++;
    }
    
    if (temp.size() == pend.size()) {
        jacob = temp;
    } else {
        int x = pend.size();
        while (temp.size() < pend.size()) {
            if (std::find(pushedNumbers.begin(), pushedNumbers.end(), x) == pushedNumbers.end()) {
                temp.push_back(x);
                pushedNumbers.push_back(x);
            } else {
                break;
            }
            x--;
        }
        jacob = temp;
    }
}

template <typename Container>
void PmergeMe<Container>::insertPendElements(Container& main, const Container& pend, const Container& jacob)
{
    typename Container::iterator it = const_cast<Container&>(jacob).begin();
    int high = 3;
    
    // Insert first element
    main.insert(main.begin(), pend[0]);
    
    while (it != const_cast<Container&>(jacob).end()) {
        if (it != const_cast<Container&>(jacob).begin() && *it > *(it - 1)) {
            high = 2 * high + 1;
        }
        
        if (*it <= static_cast<int>(pend.size()) && *it != 1) {
            int index = binarySearch(main, pend[*it - 1], high - 1);
            if (index != -1) {
                main.insert(main.begin() + index, pend[*it - 1]);
            }
        }
        it++;
    }
}

template <typename Container>
int PmergeMe<Container>::binarySearch(const Container& main, value_type target, int high)
{
    if (main.empty())
        return 0;
    
    int low = 0;
    if (high >= static_cast<int>(main.size()))
        high = main.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (tracker) tracker->incrementOperations();
        
        if (main[mid] == target) {
            return mid;
        } else if (main[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    if (low < static_cast<int>(main.size()) && target < main[low]) {
        return low;
    }
    
    return main.size();
}

template <typename Container>
const Container& PmergeMe<Container>::getData() const
{
    return data;
}

template <typename Container>
typename PmergeMe<Container>::size_type PmergeMe<Container>::getOperationCount() const
{
    return tracker ? tracker->getOperationCount() : 0;
}

// ResultFormatter template method implementation
template <typename Container1, typename Container2>
void ResultFormatter::printContainers(const Container1& vec, const Container2& deq)
{
    std::cout << "After vector:   ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "After deque:    ";
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i];
        if (i < deq.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

#endif // PMERGEME_TPP