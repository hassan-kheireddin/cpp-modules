#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
private:
    T*              _elements;
    unsigned int    _size;

public:
    // Default constructor: Empty array
    Array() : _elements(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {} // Value-initialize

    // Copy constructor (Deep Copy)
    Array(const Array &other) : _elements(NULL), _size(0) {
        *this = other;
    }

    // Destructor
    ~Array() {
        delete[] _elements;
    }

    // Assignment operator (Deep Copy)
    Array &operator=(const Array &other) {
        if (this != &other) {
            // Delete existing resources
            delete[] _elements;
            _size = other._size;

            // Allocate new memory and copy elements
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; ++i) {
                    _elements[i] = other._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }

    // Subscript operator
    T &operator[](unsigned int index) {
        if (index >= _size) {
            throw std::exception();
        }
        return _elements[index];
    }

    // Const subscript operator
    const T &operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::exception();
        }
        return _elements[index];
    }

    // Size member function
    unsigned int size() const {
        return _size;
    }
};

#endif