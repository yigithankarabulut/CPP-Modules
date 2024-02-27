#include "RPN.hpp"
#include <cstring>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) { *this = other; }

RPN& RPN::operator=(const RPN& other) { mStack = other.mStack; return *this; }

void RPN::exit_error() { std::cout << "Error" << std::endl; exit(1); }

bool isOperator(char c) {
    return c == PLUS || c == MINUS || c == MULTI || c == DIVIDE;
}

bool isValidInput(char* input) {
    return input[0] && !input[1] && (isOperator(input[0]) || isdigit(input[0]));
}

std::string RPN::checkInput(char* input)
{
    size_t operatorCount = 0, digitCount = 0;
    std::string ret;
    char *token = std::strtok(input, " ");

    while (token != NULL)
    {
        if (!isValidInput(token))
            exit_error();

        if (isOperator(token[0]))
            ++operatorCount;
        else
            ++digitCount;

        ret += token[0];
        token = std::strtok(NULL, " ");
    }

    if (operatorCount == 0 || digitCount == 1)
        exit_error();

    return ret;
}

void RPN::processInput(char* input)
{
	std::string mStr = checkInput(input);
	std::stack<int> mStack;
	int x = 0, y = 0;

	for (size_t i = 0; i < mStr.size(); ++i) {
		if (isdigit(mStr[i]))
			mStack.push(mStr[i] - 48);
		else
		{
            if (mStack.size() < 2)
                exit_error();
			x = mStack.top(); mStack.pop();
			y = mStack.top(); mStack.pop();
            if (mStr[i] == PLUS)
                mStack.push(x + y);
            else if (mStr[i] == MINUS)
                mStack.push(y - x);
            else if (mStr[i] == MULTI)
                mStack.push(x * y);
            else if (mStr[i] == DIVIDE)
                mStack.push(y / x);
        }
    }
    std::cout << mStack.top() << std::endl;
}
