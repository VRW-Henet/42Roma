#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
private:
    std::string _expr;
    std::stack<int> _stack;

public:
    RPN(std::string expr);
    ~RPN(){};

    RPN(const RPN &src);
    RPN &operator=(const RPN &rhs);

    bool evaluate();
};

#endif