#pragma once

#include <stack>
#include <iostream>

#define PLUS '+'
#define MINUS '-'
#define MULTI '*'
#define DIVIDE '/'

class RPN
{
    public:
        std::string checkInput(char* input);
        void processInput(char* input);
        void exit_error();
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
    private:
        std::stack<int> mStack;
};
