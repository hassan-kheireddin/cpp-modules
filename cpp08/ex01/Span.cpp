#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        max_size = other.max_size;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= max_size) {
        throw std::runtime_error("Span is full");
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = sorted[1] - sorted[0];
    unsigned int currentSpan = 0;
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        currentSpan = sorted[i + 1] - sorted[i];
        minSpan = std::min(minSpan, currentSpan);
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}