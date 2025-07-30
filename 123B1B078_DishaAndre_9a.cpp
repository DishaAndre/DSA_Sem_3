#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};
class Queue
{
private:
    Node *rear;
    Node *front;

public:
    Queue()
    {
        rear = front = nullptr;
    }
    void push(int n)
    {
        Node *new_node = new Node;
        new_node->val = n;
        new_node->next = nullptr;
        if (rear == nullptr)
        {
            rear = front = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
    }
    void pop()
    {
        if (front == nullptr)
        {
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }
   

    bool empty(){
        if(front == nullptr){
            return true;
        }
        return false;
    }

    int top(){
        return front->val;
    }
};

class Stack
{
private:
    Queue q1, q2;

public:
    void push(int n)
    {
        q2.push(n);

        while (!q1.empty())
        {
            q2.push(q1.top());
            q1.pop();
        }

        Queue q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
        {
            return;
        }

        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.top();
    }
};

int main()
{

    Stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1.top() <<endl;
    s1.pop();
    cout << s1.top() <<endl;

    return 0;
}
