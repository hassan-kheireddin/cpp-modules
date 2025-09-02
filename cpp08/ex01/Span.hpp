#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

class Span {
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

    Span(); // Private default constructor

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    unsigned int getSize() const;
    unsigned int getMaxSize() const;
};

// Template implementation must be in the header
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    unsigned int dist = std::distance(begin, end);
    if (_numbers.size() + dist > _maxSize) {
        throw std::runtime_error("Adding these numbers would exceed capacity");
    }
    _numbers.insert(_numbers.end(), begin, end);
}

#endif