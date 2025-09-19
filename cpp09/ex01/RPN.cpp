#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    _stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    
    for (size_t i = 0; i < token.length(); i++) {
        if (!std::isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

int RPN::performOperation(int a, int b, const std::string& op) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Error: division by zero");
        }
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}

int RPN::evaluate(const std::string& expression) {
    if (expression.empty()) {
        throw std::runtime_error("Error: empty expression");
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isNumber(token)) {
            // Convert to integer and push to stack
            int num = std::atoi(token.c_str());
            if (num < 0 || num > 9) {
                throw std::runtime_error("Error: number must be between 0 and 9");
            }
            _stack.push(num);
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: not enough operands for operator '" + token + "'");
            }
            
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            
            int result = performOperation(a, b, token);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error: invalid token '" + token + "'");
        }
    }
    
    if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression - too many operands");
    }
    
    return _stack.top();
}