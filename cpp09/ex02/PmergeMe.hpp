#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>
#include <algorithm>
#include <iterator>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void run(int argc, char **argv);

private:
    // Comparison counter
    size_t comparisonCount;

    // Helpers
    bool isPositiveInteger(const std::string &s);
    int toInt(const std::string &s);

    // Ford–Johnson algorithm
    std::vector<int> fordJohnsonSort(std::vector<int> input);
    std::deque<int> fordJohnsonSort(std::deque<int> input);

    // Core steps
    template <typename Container>
    Container fordJohnson(Container input);

    template <typename Container>
    void pairElements(Container &mainChain, Container &pendChain, const Container &input);

    template <typename Container>
    void insertPend(Container &mainChain, Container &pendChain);

    template <typename Container>
    size_t binarySearchBounded(const Container &mainChain, int value, size_t low, size_t high);

    // Jacobsthal sequence generation
    std::vector<size_t> jacobsthalOrder(size_t n);

    // Wrapped compare
    bool compare(int a, int b);

    // Printing
    template <typename Container>
    void printContainer(const std::string &prefix, const Container &c);
};

#endif
