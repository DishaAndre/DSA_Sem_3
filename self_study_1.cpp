#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *NextPointer;
    Node *PreviousPointer;
    Node(int d) : data(d), NextPointer(nullptr), PreviousPointer(nullptr) {}
};

class CircularLinkedlist
{
public:
    Node *HeadPointer;
    Node *TailPointer;

    CircularLinkedlist() : HeadPointer(nullptr), TailPointer(nullptr) {}

    bool IfCircularLinkedListIsEmpty()
    {
        return HeadPointer == nullptr;
    }

    void AddingAnElementIntoList(int data)
    {
        Node *NewNode = new Node(data);
        if (IfCircularLinkedListIsEmpty())
        {
            HeadPointer = TailPointer = NewNode;
            NewNode->NextPointer = NewNode;
            NewNode->PreviousPointer = NewNode;
        }
        else
        {
            TailPointer->NextPointer = NewNode;
            NewNode->PreviousPointer = TailPointer;
            NewNode->NextPointer = HeadPointer;
            HeadPointer->PreviousPointer = NewNode;
            TailPointer = NewNode;
        }
    }

    void DeleteFirstElementFromCircularLinkedList()
    {
        if (IfCircularLinkedListIsEmpty())
        {
            cout << "List Is Empty " << endl;
            return;
        }
        Node *TemporaryPointer = HeadPointer;
        if (HeadPointer->NextPointer == HeadPointer)
        {
            HeadPointer = TailPointer = nullptr;
        }
        else
        {
            HeadPointer = HeadPointer->NextPointer;
            HeadPointer->PreviousPointer = TailPointer;
            TailPointer->NextPointer = HeadPointer;
        }
        cout << "First Element: " << TemporaryPointer->data << " is removed from the list " << endl;
        delete TemporaryPointer;
    }

    void DeleteLastElementFromCircularLinkedList()
    {
        if (IfCircularLinkedListIsEmpty())
        {
            cout << "List Is Empty " << endl;
            return;
        }
        Node *TemporaryPointer = TailPointer;
        if (TailPointer->PreviousPointer == TailPointer)
        {
            HeadPointer = TailPointer = nullptr;
        }
        else
        {
            TailPointer = TailPointer->PreviousPointer;
            TailPointer->NextPointer = HeadPointer;
            HeadPointer->PreviousPointer = TailPointer;
        }
        cout << "Last Element: " << TemporaryPointer->data << " is removed from the list " << endl;
        delete TemporaryPointer;
    }

    void DisplayingTheList()
    {
        if (IfCircularLinkedListIsEmpty())
        {
            cout << "List Is Empty " << endl;
            return;
        }
        Node *TemporaryPointer = HeadPointer;
        cout << "List elements: ";
        do
        {
            cout << TemporaryPointer->data << " ";
            TemporaryPointer = TemporaryPointer->NextPointer;
        } while (TemporaryPointer != HeadPointer);
        cout << endl;
    }
};

int main()
{
    CircularLinkedlist cc;
    int choice;
    while (true)
    {
        cout << "\n1 - Add Element " << endl
             << "2 - Remove The First Element of The List " << endl
             << "3 - Remove The Last Element of The List " << endl
             << "4 - Display The List " << endl
             << "5 - Exit " << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int data;
            cout << "Enter Element: ";
            cin >> data;
            cc.AddingAnElementIntoList(data);
        }
        else if (choice == 2)
        {
            cc.DeleteFirstElementFromCircularLinkedList();
        }
        else if (choice == 3)
        {
            cc.DeleteLastElementFromCircularLinkedList();
        }
        else if (choice == 4)
        {
            cc.DisplayingTheList();
        }
        else if (choice == 5)
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Enter a Valid Input" << endl;
        }
    }
    return 0;
}
