#include <iostream>
using namespace std;

struct Node
{
    string name;
    long long int num;
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
        rear = front = NULL;
    }
    void enqueue(string n, long long int no)
    {
        Node *new_customer = new Node;
        new_customer->name = n;
        new_customer->num = no;
        if (rear == NULL)
        {
            rear = front = new_customer;
        }
        else
        {
            rear->next = new_customer;
            rear = new_customer;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Empty Queue" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        cout << "details that are dequeued"<< endl << temp->name << " " << temp->num << endl;
        delete temp;
    }
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << "customer details: " << endl;
        while (temp != NULL)
        {
            cout << temp->name << " " << temp->num << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue q1;
    q1.enqueue("Disha", 7847453498);
    q1.enqueue("Sanskruti", 1234567890);
    q1.enqueue("Soham", 5866472390);
    q1.enqueue("Harry", 7643765497);
    q1.display();
    q1.dequeue();
    cout << "\n";
    q1.display();
    return 0;
}