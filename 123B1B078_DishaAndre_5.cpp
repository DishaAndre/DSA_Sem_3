/*Name: Disha Andre
  PRN: 123B1B078
  Assignment no: 5
  
  In code:
    Functions used are:
    1)Create a locations list on circular route.
    2)Display the location list on circular route. 
    3)Insert a new location at beginning.
    4)Search a new location at end.
    5)Delete a location at beginning.
    6)Delete a location at end.
    7)Delete a given location .
    7)Search the location on route.
    */
    

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

class circular_route {
    Node* head;

public:
    circular_route() : head(NULL) {}

    void add_Begin(string loc) {
        Node* newNode = new Node();
        newNode->data = loc;
        newNode->next = head;
        
        if (head != NULL) {
            Node* tail = head->prev;
            tail->next = newNode;  
            newNode->prev = tail;   
        } else {
            newNode->prev = newNode; 
        }
        
        head = newNode; 
        if (!newNode->next) { 
            head->next = head; 
            head->prev = head; 
        }
    }

    void add_End(string loc) {
        Node* newNode = new Node();
        newNode->data = loc;
        
        
        if (head == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void delete_Node(string loc) {
        if (!head) return;

        Node* temp = head;
        do {
            if (temp->data == loc) {
                if (temp->prev != temp) { 
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                } else { 
                    delete head;
                    head = NULL;
                    return;
                }
                if (temp == head) { 
                    head = temp->next;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void delete_Begin() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        if (temp->next == head) { // Only one node
            delete head;
            head = NULL;
        } else {
            Node* tail = head->prev;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void delete_End() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* tail = head->prev;
        if (tail == head) { // Only one node
            delete head;
            head = NULL;
        } else {
            tail->prev->next = head;
            head->prev = tail->prev;
            delete tail;
        }
    }
/*
    int search_Location(string loc) {
        if (!head) {
            cout << "List is empty.\n";
            return 0;
        }
        Node* temp = head;
        do {
            if (temp->data == loc) {
                return 1;
            }
            temp = temp->next;
        } while (temp != head);
        return 0;
    }
*/
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " - ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    circular_route l1;

    int ch;
    string loc;

    do {
        cout << "\nMenu:\n1. Add location at beginning\n2. Add location at end\n3. Delete location\"4. Delete first location\n"<<
        "5. Delete last location\n6. Search location\n7. Display all locations\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter location to add at beginning: ";
                cin >> loc;
                l1.add_Begin(loc);
                break;
            case 2:
                cout << "Enter location to add at end: ";
                cin >> loc;
                l1.add_End(loc);
                break;
            case 3:
                cout << "Enter location to delete: ";
                cin >> loc;
                l1.delete_Node(loc);
                break;
            case 4:
                l1.delete_Begin();
                break;
            case 5:
                l1.delete_End();
                break;
           /* case 6:
                cout << "Enter location to search: ";
                cin >> loc;
                if (l1.search_Location(loc)) {
                    cout << "Location found\n";
                } else {
                    cout << "Location not found\n";
                }
                break;*/
            case 7:
                l1.display();
                break;
            case 8:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (ch != 8);
    return 0;
}
