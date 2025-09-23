#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparisonCount(0) {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositiveInteger(const std::string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return !s.empty();
}

int PmergeMe::toInt(const std::string &s) {
    long val = std::strtol(s.c_str(), NULL, 10);
    if (val <= 0 || val > INT_MAX)
        throw std::runtime_error("Error");
    return static_cast<int>(val);
}

bool PmergeMe::compare(int a, int b) {
    ++comparisonCount;
    return a < b;
}

// ========== Jacobsthal sequence ==========
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n) {
    std::vector<size_t> seq;
    if (n == 0) return seq;

    // Generate Jacobsthal numbers up to n
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);
    while (true) {
        size_t next = J[J.size() - 1] + 2 * J[J.size() - 2];
        if (next > n) break;
        J.push_back(next);
    }

    // Build insertion order (reverse expansion)
    size_t last = n;
    for (size_t k = J.size(); k > 1; --k) {
        size_t start = J[k - 1];
        for (size_t i = last; i > start; --i) {
            seq.push_back(i);
        }
        last = start;
    }
    return seq;
}

// ========== Bounded binary search ==========
template <typename Container>
size_t PmergeMe::binarySearchBounded(const Container &mainChain, int value, size_t low, size_t high) {
    while (low < high) {
        size_t mid = (low + high) / 2;
        if (compare(value, mainChain[mid]))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

// ========== Pairing phase ==========
template <typename Container>
void PmergeMe::pairElements(Container &mainChain, Container &pendChain, const Container &input) {
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (compare(a, b))
            std::swap(a, b);
        mainChain.push_back(a);
        pendChain.push_back(b);
    }
    if (input.size() % 2 == 1) {
        pendChain.push_back(input.back()); // leftover
    }
}

// ========== Insert pend elements ==========
template <typename Container>
void PmergeMe::insertPend(Container &mainChain, Container &pendChain) {
    if (pendChain.empty()) return;

    // Insert first pend element directly
    size_t pos = binarySearchBounded(mainChain, pendChain[0], 0, mainChain.size());
    mainChain.insert(mainChain.begin() + pos, pendChain[0]);

    // Insert rest in Jacobsthal order
    std::vector<size_t> order = jacobsthalOrder(pendChain.size() - 1);
    for (size_t idx : order) {
        if (idx == 0 || idx >= pendChain.size()) continue;
        int val = pendChain[idx];
        size_t pos = binarySearchBounded(mainChain, val, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, val);
    }
}

// ========== Recursive Ford–Johnson ==========
template <typename Container>
Container PmergeMe::fordJohnson(Container input) {
    if (input.size() <= 1) return input;

    Container mainChain, pendChain;
    pairElements(mainChain, pendChain, input);

    // Recurse on mainChain
    mainChain = fordJohnson(mainChain);

    // Insert pend elements
    insertPend(mainChain, pendChain);

    return mainChain;
}

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> input) {
    comparisonCount = 0;
    return fordJohnson(input);
}

std::deque<int> PmergeMe::fordJohnsonSort(std::deque<int> input) {
    comparisonCount = 0;
    return fordJohnson(input);
}

// ========== Printing ==========
template <typename Container>
void PmergeMe::printContainer(const std::string &prefix, const Container &c) {
    std::cout << prefix;
    for (size_t i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

// ========== Run ==========
void PmergeMe::run(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: no input" << std::endl;
        return;
    }

    std::vector<int> vecInput;
    std::deque<int> deqInput;

    for (int i = 1; i < argc; i++) {
        if (!isPositiveInteger(argv[i])) {
            std::cerr << "Error" << std::endl;
            return;
        }
        int num = toInt(argv[i]);
        vecInput.push_back(num);
        deqInput.push_back(num);
    }

    printContainer("Before: ", vecInput);

    // Vector timing
    clock_t start = clock();
    std::vector<int> vecSorted = fordJohnsonSort(vecInput);
    clock_t end = clock();
    double vecTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

    printContainer("After: ", vecSorted);
    std::cout << "Time to process a range of " << vecInput.size()
              << " elements with std::vector: " << vecTime << " us" << std::endl;

    // Deque timing
    start = clock();
    std::deque<int> deqSorted = fordJohnsonSort(deqInput);
    end = clock();
    double deqTime = double(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << deqInput.size()
              << " elements with std::deque: " << deqTime << " us" << std::endl;
}
