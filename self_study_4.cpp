#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* NextPointer;
};

class Stack {
public:
    Node* TopElementPointer;

    Stack() {
        TopElementPointer = nullptr;
    }

    void PushElementIsStack(string s) {
        Node* NewNode = new Node;
        NewNode->data = s;
        NewNode->NextPointer = TopElementPointer; 
        TopElementPointer = NewNode;        
    }

    string PopElementFromStack() {
        if (CheckWeatherStackIsEmpty()) {
            cout << "Empty stack" << endl;
            return "";  
        }
        string result = TopElementPointer->data;  
        Node* TemporaryPointer = TopElementPointer;            
        TopElementPointer = TopElementPointer->NextPointer;             
        delete TemporaryPointer;                
        return result;             
    }

    string PeekTopElementOfTheStack() {
        if (CheckWeatherStackIsEmpty()) {
            cout << "Stack is empty" << endl;
            return ""; 
        }
        return TopElementPointer->data;  
    }

    bool CheckWeatherStackIsEmpty() {
        return TopElementPointer == nullptr;
    }
};

class Queue {
public:
    Node* FrontPointer;
    Node* RearPointer;

    Queue() {
        FrontPointer = nullptr;
        RearPointer = nullptr;
    }

    void EnqueueElementInQeueue(string val) {
        Node* NewNode = new Node;
        NewNode->data = val;
        NewNode->NextPointer = nullptr;

        if (RearPointer) {
            RearPointer->NextPointer = NewNode; 
        } else {
            FrontPointer = NewNode; 
        }
        RearPointer = NewNode;
        cout << val << " Enqueued" << endl;
    }

    string DequeueElementFromQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return "";
        }
        string result = FrontPointer->data;
        Node* TemporaryPointer = FrontPointer; 
        FrontPointer = FrontPointer->NextPointer;
        if (FrontPointer == nullptr) {
            RearPointer = nullptr; 
        }
        delete TemporaryPointer; 
        return result; 
    }

    bool isEmpty() {
        return FrontPointer == nullptr;
    }
};

void reverseStack(Stack& stack) {
    Queue queue;
    while (!stack.CheckWeatherStackIsEmpty()) {
        queue.EnqueueElementInQeueue(stack.PopElementFromStack()); 
    }

    while (!queue.isEmpty()) {
        stack.PushElementIsStack(queue.DequeueElementFromQueue()); 
    }
}

int main() {
    Stack stack;
    int Size;

    cout << "Enter the number of elements to Push onto the stack: ";
    cin >> Size;

    for (int i = 0; i < Size; i++) {
        string value;
        cout << "Enter value for position " << (i + 1) << ": ";
        cin >> value;
        stack.PushElementIsStack(value);
    }

    cout << "Stack before reversing:" << endl;
    while (!stack.CheckWeatherStackIsEmpty()) {
        cout << stack.PeekTopElementOfTheStack() << " ";
        stack.PopElementFromStack(); 
    }
    cout << endl;

    for (int i = 0; i < Size; i++) {
        string value;
        cout << "Re-enter value for position " << (i + 1) << ": ";
        cin >> value;
        stack.PushElementIsStack(value);
    }

    reverseStack(stack);

    cout << "Stack after reversing:" << endl;
    while (!stack.CheckWeatherStackIsEmpty()) {
        cout << stack.PeekTopElementOfTheStack() << " ";
        stack.PopElementFromStack(); 
    }
    cout << endl;

    return 0;
}
