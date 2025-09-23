#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

// The algo

int RPN::calculate(const std::string &expression)
{
    std::stack<int> numbers;
    std::istringstream stream(expression);
    std::string token;

    while (stream >> token)
    {
        if (std::isdigit(token[0]) && token.length() == 1)
        {
            numbers.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (numbers.size() < 2)
                throw std::runtime_error("Error: Invalid expression (not enough operands)");

            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            if (token == "+") 
                numbers.push(a + b);
            else if (token == "-") 
                numbers.push(a - b);
            else if (token == "*") 
                numbers.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero");
                numbers.push(a / b);
            }
        }
        else
            throw std::runtime_error("Error: Invalid token in expression");

    }
    if (numbers.size() != 1)
        throw std::runtime_error("Error: Invalid expression (leftover operands)");
    return numbers.top();
}