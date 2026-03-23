#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *PreviousPointer;
    Node *NextPointer;

    Node(int d) : data(d), PreviousPointer(nullptr), NextPointer(nullptr) {}
};

class DoublyLinkedList
{
public:
    Node *HeadPointer;

    DoublyLinkedList() : HeadPointer(nullptr) {}

    bool IfDoublyLinkedListIsEmpty()
    {
        return HeadPointer == nullptr;
    }

    void AddElementToDoublyLinkedList(int data)
    {
        Node *newNode = new Node(data);
        if (IfDoublyLinkedListIsEmpty())
        {
            HeadPointer = newNode;
        }
        else
        {
            Node *TemporaryPointer = HeadPointer;
            while (TemporaryPointer->NextPointer)
            {
                TemporaryPointer = TemporaryPointer->NextPointer;
            }
            TemporaryPointer->NextPointer = newNode;
            newNode->PreviousPointer = TemporaryPointer;
        }
    }

    void RemovingDuplicateElementsFromADoublyLinkedListIfDupicateElemetsAreOneAfterAnother()
    {
        if (IfDoublyLinkedListIsEmpty())
        {
            cout << "List is empty.\n";
            return;
        }
        Node *TemporaryPointer = HeadPointer;
        while (TemporaryPointer && TemporaryPointer->NextPointer)
        {
            if (TemporaryPointer->data == TemporaryPointer->NextPointer->data)
            {
                Node *deleteNode = TemporaryPointer->NextPointer;
                TemporaryPointer->NextPointer = deleteNode->NextPointer;
                if (deleteNode->NextPointer)
                {
                    deleteNode->NextPointer->PreviousPointer = TemporaryPointer;
                }
                delete deleteNode;
            }
            else
            {
                TemporaryPointer = TemporaryPointer->NextPointer;
            }
        }
    }

    void RemovingDuplicateElementsFromADoublyLinkedListUsingMaps()
    {
        if (IfDoublyLinkedListIsEmpty())
        {
            cout << "List is empty.\n";
            return;
        }
        map<int, bool> m;
        Node *TemporaryPointer = HeadPointer;
        Node *PreviousPointer = nullptr;

        while (TemporaryPointer)
        {
            if (map[TemporaryPointer->data])
            {
                Node *deleteNode = TemporaryPointer;
                if (TemporaryPointer->NextPointer)
                {
                    TemporaryPointer->NextPointer->PreviousPointer = PreviousPointer;
                }
                if (PreviousPointer)
                {
                    PreviousPointer->NextPointer = TemporaryPointer->NextPointer;
                }
                else
                {
                    HeadPointer = TemporaryPointer->NextPointer;
                }
                TemporaryPointer = TemporaryPointer->NextPointer;
                delete deleteNode;
            }
            else
            {
                map[TemporaryPointer->data] = true;
                PreviousPointer = TemporaryPointer;
                TemporaryPointer = TemporaryPointer->NextPointer;
            }
        }
    }

    void RemovingDuplicateElementsFromADoublyLinkedListWithoutUsingMaps()
    {
        if (IfDoublyLinkedListIsEmpty())
        {
            cout << "List is empty.\n";
            return;
        }
        Node *current = HeadPointer;
        while (current)
        {
            Node *runner = current->NextPointer;
            while (runner)
            {
                if (runner->data == current->data)
                {
                    Node *deleteNode = runner;
                    runner = runner->NextPointer;
                    if (deleteNode->PreviousPointer)
                    {
                        deleteNode->PreviousPointer->NextPointer = deleteNode->NextPointer;
                    }
                    if (deleteNode->NextPointer)
                    {
                        deleteNode->NextPointer->PreviousPointer = deleteNode->PreviousPointer;
                    }
                    delete deleteNode;
                }
                else
                {
                    runner = runner->NextPointer;
                }
            }
            current = current->NextPointer;
        }
    }

    void DisplayingTheDoublyLinkedList()
    {
        if (IfDoublyLinkedListIsEmpty())
        {
            cout << "List is empty.\n";
            return;
        }
        Node *TemporaryPointer = HeadPointer;
        while (TemporaryPointer)
        {
            cout << TemporaryPointer->data << " ";
            TemporaryPointer = TemporaryPointer->NextPointer;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dd;
    int choice;
    while (true)
    {
        cout << "\n1 - Add Element\n"
             << "2 - Remove Duplicates Sequentially\n"
             << "3 - Remove Duplicates Using Map\n"
             << "4 - Remove Duplicates Without Map\n"
             << "5 - Display The List\n"
             << "6 - Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int data;
            cout << "Enter Element: ";
            cin >> data;
            dd.AddElementToDoublyLinkedList(data);
        }
        else if (choice == 2)
        {
            dd.RemovingDuplicateElementsFromADoublyLinkedListIfDupicateElemetsAreOneAfterAnother();
        }
        else if (choice == 3)
        {
            dd.RemovingDuplicateElementsFromADoublyLinkedListUsingMaps();
        }
        else if (choice == 4)
        {
            dd.RemovingDuplicateElementsFromADoublyLinkedListWithoutUsingMaps();
        }
        else if (choice == 5)
        {
            cout << "List: ";
            dd.DisplayingTheDoublyLinkedList();
        }
        else if (choice == 6)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Enter a Valid Input.\n";
        }
    }
    return 0;
}
