#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeME.hpp"

// Template method implementations

template<typename Container>
Container PmergeME::_mergeSortRecursive(Container& input, bool isVector)
{
    if (input.empty())
        return Container();
    
    if (input.size() == 1)
        return input;
    
    if (input.size() == 2) {
        Container result = input;
        _incrementOperations<Container>(isVector);
        
        if (result[0] > result[1]) {
            std::swap(result[0], result[1]);
        }
        return result;
    }
    
    Container main, pend;
    bool hasOdd = false;
    
    _setupPairs(main, pend, input, hasOdd, isVector);
    
    Container newMain = _mergeSortRecursive(main, isVector);
    
    Container newPend;
    _reconstructPendFromMain(newPend, newMain, main, pend);
    
    if (hasOdd) {
        newPend.push_back(input.back());
    }
    
    _insertionSort(newMain, newPend, isVector);
    
    return newMain;
}

template<typename Container>
void PmergeME::_setupPairs(Container& main, Container& pend, const Container& input, bool& hasOdd, bool isVector)
{
    hasOdd = (input.size() % 2 == 1);
    typename Container::const_iterator it = input.begin();
    
    while (it != input.end()) {
        if ((it + 1) == input.end()) {
            break;
        }
        
        _incrementOperations<Container>(isVector);
        
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

template<typename Container>
void PmergeME::_reconstructPendFromMain(Container& newPend, const Container& newMain,
                                       const Container& main, const Container& pend)
{
    newPend.clear();
    newPend.resize(newMain.size());
    
    for (size_t i = 0; i < newMain.size(); ++i) {
        for (size_t j = 0; j < main.size(); ++j) {
            if (main[j] == newMain[i]) {
                newPend[i] = pend[j];
                break;
            }
        }
    }
}

template<typename Container>
void PmergeME::_insertionSort(Container& main, Container& pend, bool isVector)
{
    if (pend.empty()) return;
    
    Container jacob = _generateJacobsthalIndices<Container>(pend.size());
    _processJacobsthalIndices(jacob, pend);
    _insertPendElements(main, pend, jacob, isVector);
}

template<typename Container>
Container PmergeME::_generateJacobsthalIndices(size_t size)
{
    Container jacobSequence;
    int jacobIndex = 3;
    
    while (_generateJacobsthal(jacobIndex) <= static_cast<int>(size)) {
        jacobSequence.push_back(_generateJacobsthal(jacobIndex));
        jacobIndex++;
    }
    
    return jacobSequence;
}

template<typename Container>
void PmergeME::_processJacobsthalIndices(Container& jacob, const Container& pend)
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

template<typename Container>
void PmergeME::_insertPendElements(Container& main, const Container& pend, const Container& jacob, bool isVector)
{
    typename Container::const_iterator it = jacob.begin();
    int high = 3;
    
    main.insert(main.begin(), pend[0]);
    
    while (it != jacob.end()) {
        if (it != jacob.begin() && *it > *(it - 1)) {
            high = 2 * high + 1;
        }
        
        if (*it <= static_cast<int>(pend.size()) && *it != 1) {
            int index = _binarySearch(main, pend[*it - 1], high - 1, isVector);
            if (index != -1) {
                main.insert(main.begin() + index, pend[*it - 1]);
            }
        }
        it++;
    }
}

template<typename Container>
int PmergeME::_binarySearch(const Container& main, int target, int high, bool isVector)
{
    if (main.empty())
        return 0;
    
    int low = 0;
    if (high >= static_cast<int>(main.size()))
        high = main.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        _incrementOperations<Container>(isVector);
        
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

// Template performance tracking methods
template<typename Container>
void PmergeME::_startTiming(bool isVector)
{
    if (isVector) {
        _vectorStartTime = clock();
    } else {
        _dequeStartTime = clock();
    }
}

template<typename Container>
void PmergeME::_stopTiming(bool isVector)
{
    if (isVector) {
        _vectorEndTime = clock();
    } else {
        _dequeEndTime = clock();
    }
}

template<typename Container>
void PmergeME::_incrementOperations(bool isVector)
{
    if (isVector) {
        vecOp++;
    } else {
        deqOp++;
    }
}

template<typename Container>
double PmergeME::_getElapsedTime(bool isVector) const
{
    if (isVector) {
        if (_vectorStartTime == 0 || _vectorEndTime == 0) return 0.0;
        return static_cast<double>(_vectorEndTime - _vectorStartTime) / CLOCKS_PER_SEC * 1000000; // microseconds
    } else {
        if (_dequeStartTime == 0 || _dequeEndTime == 0) return 0.0;
        return static_cast<double>(_dequeEndTime - _dequeStartTime) / CLOCKS_PER_SEC * 1000000; // microseconds
    }
}

// Specialized template implementations for _getData
template<>
inline const std::vector<int>& PmergeME::_getData<std::vector<int> >(bool isVector) const
{
    (void)isVector; // suppress unused parameter warning
    return vecData;
}

template<>
inline const std::deque<int>& PmergeME::_getData<std::deque<int> >(bool isVector) const
{
    (void)isVector; // suppress unused parameter warning
    return deqData;
}

template<typename Container>
size_t PmergeME::_getOperationCount(bool isVector) const
{
    if (isVector) {
        return vecOp;
    } else {
        return deqOp;
    }
}

#endif // PMERGEME_TPP