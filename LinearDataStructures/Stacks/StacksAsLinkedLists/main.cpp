#include <iostream>
#include <cctype> //Using isdigit function
#include <stdlib.h> //Using atoi function
#include "LinkedStack.h"
#include <math.h>
using namespace std;

void decimalToBinary(int number);
string reverseString(string text);
void validateWords(string word);
void symbolBalancing(string text);
string infixToPostfix(string infix);
string infixToPrefix(string infix);
string postfixToInfix(string postfix);
string prefixToInfix(string prefix);
string postfixToPrefix(string postfix);
string prefixToPostfix(string prefix);
void evaluatePostfix(string infix);
int precendence(char optr);

int main() {
    int choice;

    do {
        cout << endl;
        cout << "\n Press 1 to convert decimal to binary";
        cout << "\n Press 2 to reverse a sentence";
        cout << "\n Press 3 to validate a word";
        cout << "\n Press 4 for balancing symbols";
        cout << "\n Press 5 to evaluate postfix";
        cout << "\n Press 6 to convert infix to postfix";
        cout << "\n Press 7 to convert infix to prefix";
        cout << "\n Press 8 to convert postfix to infix";
        cout << "\n Press 9 to convert prefix to infix";
        cout << "\n Press 10 to convert postfix to prefix";
        cout << "\n Press 11 to convert prefix to postfix";
        cout << "\n Press 0 to Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                int element;
                cout << "\nEnter the decimal number: ";
                cin >> element;
                cout << "\nThe decimal number is: ";
                decimalToBinary(element);
                cout << endl;
                break;
            }
            case 2: {
                string text;
                cout << "\nEnter the text to reverse: ";
                cin.ignore();
                getline(cin, text);
                cout << "\nThe reversed text is: ";
                cout << reverseString(text);
                cout << endl;
                break;
            }
            case 3: {
                string text;
                cout << "\nEnter the text to validate: ";
                cin >> text;
                validateWords(text);
                cout << endl;
                break;
            }
            case 4: {
                string text;
                cout << "\nEnter the symbols to validate: ";
                cin >> text;
                symbolBalancing(text);
                cout << endl;
                break;
            }
            case 5: {
                string expr;
                cout << "\nEnter the postfix to evaluate: ";
                cin >> expr;
                evaluatePostfix(expr);
                cout << endl;
                break;
            }
            case 6: {
                string infix;
                cout << "\nEnter the infix convert: ";
                cin >> infix;
                string result = infixToPostfix(infix);
                cout << "Postfix is: " << result << endl;
                break;
            }
            case 7: {
                string infix;
                cout << "\nEnter the infix to convert: ";
                cin >> infix;
                string result = infixToPrefix(infix);
                cout << "Prefix is: " << result << endl;
                break;
            }
            case 8: {
                string postfix;
                cout << "\nEnter the postfix to convert: ";
                cin >> postfix;
                string result = postfixToInfix(postfix);
                cout << "Infix is: " << result << endl;
                break;
            }
            case 9: {
                string prefix;
                cout << "\nEnter the prefix to convert: ";
                cin >> prefix;
                string result = prefixToInfix(prefix);
                cout << "Infix is: " << result << endl;
                break;
            }
            case 10: {
                string postfix;
                cout << "\nEnter the postfix to convert: ";
                cin >> postfix;
                string result = postfixToPrefix(postfix);
                cout << "Prefix is: " << result << endl;
                break;
            }
            case 11: {
                string prefix;
                cout << "\nEnter the prefix to convert: ";
                cin >> prefix;
                string result = prefixToPostfix(prefix);
                cout << "Postfix is: " << result << endl;
                break;
            }
            case 0:
                exit(0);
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (true);
}

void decimalToBinary(int number) {
    LinkedStack<int> stack;

    while (number != 0) {
        stack.push(number % 2);
        number /= 2;
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }

}

string reverseString(string text) {
    LinkedStack<char> stack;
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        stack.push(text[i]);
    }

    while (!stack.isEmpty()) {
        char ch = stack.pop();
        result += ch;
    }

    return result;
}

void validateWords(string text) {
    LinkedStack<char> stack;
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == 'a') {
            stack.push(text[i]);
        } else if (ch == 'b') {
            if (stack.isEmpty()) {
                cerr << "Number of b's are greater than number of a's" << endl;
            }
            stack.pop();
        } else {
            cerr << "Character has value except a and b" << endl;
        }
    }

    if (stack.isEmpty()) {
        cout << "Valid input word";
    } else {
        cerr << "Number of a's are greater than number of b's!" << endl;
    }
}

void symbolBalancing(string text) {
    LinkedStack<char> stack;
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == '[' || ch == '{' || ch == '(' || ch == '<') {
            stack.push(text[i]);
        } else if (ch == ']' || ch == '}' || ch == ')' || ch == '>') {
            if (stack.isEmpty()) {
                cerr << "Number of closing brackets are greater than number of opening brackets" << endl;
                return;
            }
            char ch = stack.pop();
            if (
                (text[i] == '[' && ch != ']') ||
                (text[i] == '{' && ch != '}') ||
                (text[i] == '(' && ch != ')') ||
                (text[i] == '<' && ch != '>')
                ) {
                cerr << "Symbol missing!" << endl;
                return;
            }
        } else {
            cerr << "Number of opening brackets are greater than number of closing brackets" << endl;
        }
    }
}

int precendence(char optr) {
    if (optr == '^')
        return 3;
    else if (optr == '*' || optr == '/')
        return 2;
    else if (optr == '+' || optr == '-')
        return 1;

    return -1;
}

void evaluatePostfix(string expr) {
    LinkedStack<double> stack;

    for (int i = 0; i < expr.length(); i++) {
        if (isdigit(expr[i])) {
            char ch = expr[i];
            double dbl = atof(&ch);
            stack.push(dbl);
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^') {
            double element1 = stack.pop();
            double element2 = stack.pop();
            switch (expr[i]) {
                case '+':
                    stack.push(element2 + element1);
                    break;
                case '-':
                    stack.push(element2 - element1);
                    break;
                case '*':
                    stack.push(element2 * element1);
                    break;
                case '/':
                    stack.push(element2 / element1);
                    break;
                case '^':
                    stack.push(pow(element2, element1));
            }
        }
    }
    cout << "Final Answer is: " << stack.pop() << endl;
}

string infixToPostfix(string infix) {
    LinkedStack<char> stack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i])) {
            postfix = infix[i];
        } else if (infix[i] == '(') {
            stack.push(infix[i]);
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            if (stack.isEmpty()) {
                stack.push(infix[i]);
            } else {
                while (!stack.isEmpty() && stack.topValue() != '(' && precendence(stack.topValue()) >= precendence(infix[i])) {
                    postfix += stack.pop();
                }
                stack.push(infix[i]);
            }
        } else if (infix[i] == ')') {
            while (stack.topValue() != '(') {
                postfix += stack.topValue();
                stack.pop();
            }
            stack.pop();
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    LinkedStack<char> stack;
    string prefix = "";
    infix = reverseString(infix);

    for (int i = 0; i < infix.length(); i++) {
        if (isalpha(infix[i])) {
            prefix = infix[i];
        } else if (infix[i] == ')') {
            stack.push(infix[i]);
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            if (stack.isEmpty()) {
                stack.push(infix[i]);
            } else {
                while (!stack.isEmpty() && stack.topValue() != ')' && precendence(stack.topValue()) >= precendence(infix[i])) {
                    prefix += stack.pop();
                }
                stack.push(infix[i]);
            }
        } else if (infix[i] == '(') {
            while (stack.topValue() != ')') {
                prefix += stack.topValue();
                stack.pop();
            }
            stack.pop();
        }
    }

    while (!stack.isEmpty()) {
        prefix += stack.pop();
    }

    return reverseString(prefix);
}

string postfixToInfix(string postfix) {
    LinkedStack<string> stack;

    for (int i = 0; i < postfix.length(); i++) {
        if (isalpha(postfix[i])) {
            string str;
            str += postfix[i];
            stack.push(str);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            string element1 = stack.pop();
            string element2 = stack.pop();
            string result = "(" + element2 + postfix[i] + element1 + ")";
            stack.push(result);
        }
    }
    return stack.pop();
}

string prefixToInfix(string prefix) {
    LinkedStack<string> stack;
    prefix = reverseString(prefix);
    for (int i = 0; i < prefix.length(); i++) {
        if (isalpha(prefix[i])) {
            string str;
            str += prefix[i];
            stack.push(str);
        } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            string element1 = stack.pop();
            string element2 = stack.pop();
            string result = ")" + element2 + prefix[i] + element1 + "(";
            stack.push(result);
        }
    }
    return reverseString(stack.pop());
}

string postfixToPrefix(string postfix) {
    string infix = postfixToInfix(postfix);
    string prefix = infixToPrefix(infix);
    return prefix;
}

string prefixToPostfix(string prefix) {
    string infix = prefixToInfix(prefix);
    string postfix = infixToPostfix(infix);
    return postfix;
}