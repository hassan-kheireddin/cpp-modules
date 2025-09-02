#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Span is full");
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = sorted[1] - sorted[0]; // Initialize with first span
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        unsigned int currentSpan = sorted[i + 1] - sorted[i];
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}

unsigned int Span::getSize() const { return _numbers.size(); }
unsigned int Span::getMaxSize() const { return _maxSize; }