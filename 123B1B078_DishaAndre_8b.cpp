#include <iostream>
#include <cstring>

using namespace std;
const int MAX_SIZE = 100;

class Stack {
    private:
        int top;
        int arr[MAX_SIZE];
    public:
        Stack() {
            top = -1;
        }
    void push(int x) {
        if (top == MAX_SIZE- 1) {
            cout << "Stack overflow" << endl;
        } else {
            arr[++top] = x;
        }
    }
    int pop() {
        if (top ==-1) {
            cout << "Stack underflow" << endl;
            return-1;
        } else {
            return arr[top--];
        }
    }
    int peek() {
        if (top ==-1) {
        return-1;
        } else {
        return arr[top];
        }
    }
    bool isEmpty() {
        return top ==-1;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}
int precedence(char c) {
    if (c == '*' || c == '/') {
    return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isDigit(c)) {
            postfix[j++] = c;
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix[j++] = s.pop();
            }
        s.push(c);
    }
        i++;
    }
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }
    postfix[j] = 0;
}

int evaluatePostfix(char* postfix) {
    Stack s;
    int i = 0;
    while (postfix[i] != 0) {
        char c = postfix[i];
        if (isDigit(c)) {
            s.push(c- '0');
        }
        else if (isOperator(c)) {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;
        if (c == '+') {
            result = val1 + val2;
        } else if (c == '-') {
            result = val1- val2;
        } else if (c == '*') {
            result = val1 * val2;
        } else if (c == '/') {
            result = val1 / val2;
        }
        s.push(result);
        }
        i++;
    }
    return s.pop();
 }

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    cout << "Enter expression : ";
    cin >> infix;
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Postfix evaluation : " << result << endl;
    return 0;
}