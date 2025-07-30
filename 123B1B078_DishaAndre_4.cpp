/*Name: Disha Andre
  PRN: 123B1B078
  Assignment no: 4
  
  In code:
    Functions used are:
    1)Create a Text editor
    2)Display the text 
    3)Insert a new text
    4)Search a word 
    5)Delete a word
    6)Copy the text 
    7)Reverse the text
    */
    
#include <iostream>
using namespace std;

struct node
{
    string data;
    node *next;
    node *prev;
};

class editor
{
public:
    node *head;
    node *tail;

    editor()
    {
        head = nullptr;
        tail = nullptr;
    }

    void display()
    {
        if(!head){
            cout<<"Empty list."<<endl;
            return;
        }
        node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(string data)
    {
        node *new_node = new node;
        new_node->data = data;

        if (!head && !tail)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = nullptr;
        tail = new_node;
    }

    int searchWord(string word)
    {
        node *temp = head;
        int count = 1;

        while (temp)
        {
            if (temp->data == word)
            {
                cout << "The word " << word << " is present at position " << count << endl;
                return count;
            }
            temp = temp->next;
            count++;
        }

        cout << "Word not found" << endl;
        return -1;
    }

   /* void deleteWord(string s)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        int pos = searchWord(s);
        if (pos == -1)
        {
            cout << "Word not found" << endl;
            return;
        }
        node *temp = head;
        if (pos == 1)
        {
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete temp;
            return;
        }
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *ex = temp->next;
        if (ex->next == nullptr)
        {
            temp->next = nullptr;
            tail = temp;
            delete ex;
            return;
        }
        temp->next = ex->next;
        if (ex->next)
        {
            ex->next->prev = temp;
        }
        delete ex;
    } */

    node *RemoveElement(string s)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return head;
        }
        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == s)
            {
                if (head->next == nullptr)
                {
                    head = nullptr;
                    tail = nullptr;
                    delete temp;
                    return head;
                }

                if (temp->prev == nullptr)
                {
                    head = head->next;
                    head->prev = nullptr;
                    delete temp;
                    return head;
                }

                if (temp->next == nullptr)
                {
                    temp->prev->next = nullptr;
                    tail = temp->prev;
                    delete temp;
                    return head;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return head;
            }

            temp = temp->next;
        }
        cout << "Element not found" << endl;
        return head;
    }

   /* void CopyText(editor &l1)
    {

        if (head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }
        node *p = head;
        while (p)
        {
            l1.insert(p->data);
            p = p->next;
        }
    }*/

    void reverse()
    {
        node *temp = nullptr; 
        node *current = head;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; 
        }
        if (temp != nullptr)
        {
            head = temp->prev; 
        }
    }
};

int main()
{
    editor ed;
    ed.display();
    ed.insert("Welcome");
    ed.insert("to");
    ed.insert("data");
    ed.insert("structure");
    ed.insert("lab.");

    cout << "list : ";
    ed.display();
    cout << endl;

    ed.searchWord("data");
    cout<<endl;
 
    ed.RemoveElement("structure");
    cout << "list without word 'structure' : ";
    ed.display();
    cout << endl;

    editor d1;
    /*ed.CopyText(d1);

    cout << "List 1 : ";
    ed.display();
    cout << endl;

    cout << "List 2 : ";
    d1.display();
    cout << endl;
*/
    ed.reverse();
    cout << "Reversed list : ";
    ed.display();
    cout << endl;

    return 0;
}
