//Assignment no: 10

/*
Job class representing a job with a name and priority
Method to insert job details
Method to display job details
Method to get the job priority
Method to get the job name
Queue class implementing a double-ended circular queue for jobs
Driver code to demonstrate the job scheduling system
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#define max 5  

using namespace std;

class Job {
    string name;   
    int priority;  

public:
   
    Job() {
        name = " ";
        priority = 0;
    }

    Job(string n, int num) {
        name = n;
        priority = num;
    }

    void insert(string n, int num) {
        name = n;
        priority = num;
    }

    void display() {
        cout << "Job Name: " << name << "\tPriority: " << priority << endl;
    }

    int getPriority() {
        return priority;
    }

    string getName() {
        return name;
    }
};

class Queue {
    int front, rear; 
    Job* queue = new Job[max]; 

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % max == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertAtRear(string n, int num) {
        if (isFull()) {
            cout << "Queue is full. No more jobs can be added.\n";
            return;
        }

        Job newJob(n, num);

        if (isEmpty()) {
            rear = front = 0;  
        } else {
            int position = (rear + 1) % max;

            int i = rear;
            while (i != front) {
                if (queue[i].getPriority() < num) {
                    break;  
                }
                position = i;
                i = (i - 1 + max) % max;  
            }
          
            for (int j = rear; j != position; j = (j - 1 + max) % max) {
                queue[j] = queue[(j - 1 + max) % max];
            }
            queue[position] = newJob; 
            rear = (rear + 1) % max;  
        }
    }

    void insertAtFront(string n, int num) {
        if (isFull()) {
            cout << "Queue is full. No more jobs can be added.\n";
            return;
        }

        Job newJob(n, num);

        if (isEmpty()) {
            rear = front = 0;  
            queue[front] = newJob;  
        } else {
            int position = front;  

            while (position != rear) {
                if (queue[position].getPriority() < num) {
                    break;  
                }
                position = (position + 1) % max; 
            }
            for (int j = front; j != position; j = (j + 1) % max) {
                queue[j] = queue[(j + 1) % max];
            }
            queue[position] = newJob;  
            front = (front - 1 + max) % max;  
        }
    }

    void deleteFromFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Doing job: ";
        queue[front].display();
        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % max;  
        }
    }

    void deleteFromRear() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Doing job: ";
        queue[rear].display();
        if (front == rear) {
            front = rear = -1;  
        } else {
            rear = ((rear - 1) + max) % max;  
        }
    }

    void searchJob(string n) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        int position = front;
        bool found = false;

        while (true) {
            if (queue[position].getName() == n) {
                cout << "Job found: ";
                queue[position].display();
                found = true;
                break;
            }
            if (position == rear) break;  
            position = (position + 1) % max; 
        }

        if (!found) {
            cout << "Job " << n << " not found in the queue.\n";
        }
    }

    void displayJobs() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Jobs in the queue:\n";
        int position = front;

        while (true) {
            queue[position].display();
            if (position == rear) break; 
            position = (position + 1) % max;  
        }
    }
};

int main() {
    Queue q;  
    while (true) {
        cout << "\nJob Scheduling Menu:\n";
        cout << "1. Add Job at Rear\n";
        cout << "2. Add Job at Front\n";
        cout << "3. Remove Job from Front\n";
        cout << "4. Remove Job from Rear\n";
        cout << "5. Search Job\n";
        cout << "6. Display All Jobs\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        string name;
        int priority;

        switch (choice) {
            case 1:
                cout << "Enter Job Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Job Priority: ";
                cin >> priority;
                q.insertAtRear(name, priority);
                break;

            case 2:
                cout << "Enter Job Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Job Priority: ";
                cin >> priority;
                q.insertAtFront(name, priority);
                break;

            case 3:
                q.deleteFromFront();
                break;

            case 4:
                q.deleteFromRear();
                break;

            case 5:
                cout << "Enter Job Name to Search: ";
                cin.ignore();
                getline(cin, name);
                q.searchJob(name);
                break;

            case 6:
                q.displayJobs();
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Please enter a valid choice.\n";
        }
    }
}
