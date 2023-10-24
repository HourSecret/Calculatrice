#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <cmath>
#include <vector>

// Token type enumeration
enum class TokenType { Number, Operator, LeftParen, RightParen };

// Token structure
struct Token {
    TokenType typee;
    double value; // For numbers
    char op;      // For operators

    // Constructors
    Token(double val) : typee(TokenType::Number), value(val), op(0) {}
    Token(char opr) : typee(TokenType::Operator), value(0), op(opr) {}
    Token(TokenType t) : typee(t), value(0), op(0) {}
};

// Function to tokenize the input expression
std::vector<Token> tokenize(const std::string& expression) {
    std::vector<Token> tokens;
    std::istringstream iss(expression);

    char c;
    while (iss.get(c)) {
        if (std::isdigit(c) || c == '.') {
            iss.unget(); // Put the character back into the stream
            double num;
            iss >> num;
            tokens.emplace_back(num);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            tokens.emplace_back(c);
        } else if (c == '(') {
            tokens.emplace_back(TokenType::LeftParen);
        } else if (c == ')') {
            tokens.emplace_back(TokenType::RightParen);
        }
    }

    return tokens;
}

// Function to evaluate the expression
double evaluateExpression(const std::vector<Token>& tokens) {
    std::stack<double> operandStack;
    std::stack<char> operatorStack;

    for (const auto& token : tokens) {
        if (token.typee == TokenType::Number) {
            operandStack.push(token.value);
        } else if (token.typee == TokenType::Operator) {
            while (!operatorStack.empty() &&
                   ((token.op == '+' || token.op == '-') && (operatorStack.top() == '*' || operatorStack.top() == '/'))) {
                // Pop and evaluate higher precedence operators
                double operand2 = operandStack.top();
                operandStack.pop();

                double operand1 = operandStack.top();
                operandStack.pop();

                char op = operatorStack.top();
                operatorStack.pop();

                double result;
                switch (op) {
                    case '+': result = operand1 + operand2; break;
                    case '-': result = operand1 - operand2; break;
                    case '*': result = operand1 * operand2; break;
                    case '/': result = operand1 / operand2; break;
                }

                operandStack.push(result);
            }

            operatorStack.push(token.op);
        } else if (token.typee == TokenType::LeftParen) {
            operatorStack.push('(');
        } else if (token.typee == TokenType::RightParen) {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                // Pop and evaluate until matching '('
                double operand2 = operandStack.top();
                operandStack.pop();

                double operand1 = operandStack.top();
                operandStack.pop();

                char op = operatorStack.top();
                operatorStack.pop();

                double result;
                switch (op) {
                    case '+': result = operand1 + operand2; break;
                    case '-': result = operand1 - operand2; break;
                    case '*': result = operand1 * operand2; break;
                    case '/': result = operand1 / operand2; break;
                }

                operandStack.push(result);
            }

            // Pop the '('
            operatorStack.pop();
        }
    }

    // Evaluate remaining operators
    while (!operatorStack.empty()) {
        double operand2 = operandStack.top();
        operandStack.pop();

        double operand1 = operandStack.top();
        operandStack.pop();

        char op = operatorStack.top();
        operatorStack.pop();

        double result;
        switch (op) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
        }

        operandStack.push(result);
    }

    return operandStack.top();
}
int main() {
    std::cout << "Enter an arithmetic expression: ";
    std::string expression;
    std::getline(std::cin, expression);

    // Tokenize the expression
    std::vector<Token> tokens = tokenize(expression);

    // Evaluate the expression
    double result = evaluateExpression(tokens);

    // Print the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}

