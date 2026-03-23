#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *NextPointer;
};

class Stack
{
public:
    Node *TopElementPointer;

    Stack()
    {
        TopElementPointer = nullptr;
    }

    void PushElementInStack(string s)
    {
        Node *NewNode = new Node;
        NewNode->data = s;
        NewNode->NextPointer = TopElementPointer;
        TopElementPointer = NewNode;
    }

    string PopElementFromStack()
    {
        if (CheckIfTheStackIsEmpty())
        {
            cout << "Empty stack" << endl;
            return "";
        }
        string result = TopElementPointer->data;
        Node *TemporaryPointer = TopElementPointer;
        TopElementPointer = TopElementPointer->NextPointer;
        delete TemporaryPointer;
        return result;
    }

    string PeekTheTopElementInStack()
    {
        if (CheckIfTheStackIsEmpty())
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        return TopElementPointer->data;
    }

    bool CheckIfTheStackIsEmpty()
    {
        return TopElementPointer == nullptr;
    }
};

bool CheckIfParenthesesAreBalanced(const string &expression)
{
    Stack stack;
    for (char character : expression)
    {
        if (character == '(' || character == '{' || character == '[')
        {
            stack.PushElementInStack(string(1, character));
        }
        else if (character == ')' || character == '}' || character == ']')
        {
            if (stack.CheckIfTheStackIsEmpty())
            {
                return false;
            }
            string TopElementPointer = stack.PopElementFromStack();
            if ((character == ')' && TopElementPointer != "(") ||
                (character == '}' && TopElementPointer != "{") ||
                (character == ']' && TopElementPointer != "["))
            {
                return false;
            }
        }
    }
    return stack.CheckIfTheStackIsEmpty();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (CheckIfParenthesesAreBalanced(expression))
    {
        cout << "The expression has balanced parentheses." << endl;
    }
    else
    {
        cout << "The expression does not have balanced parentheses." << endl;
    }

    return 0;
}
