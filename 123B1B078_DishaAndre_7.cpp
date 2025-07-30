
/*
Name:- Disha Andre
PRN:- 123B1B078

1)Node Structure
2)Stack Class:
    (a)push: Add a new page to the top of the stack.
    (b)pop: Remove and return the page from the top of the stack.
    (c)peek: Return the page at the top without removing it.
    (d)isEmpty: Check if the stack is empty.
3)Browser Class: 
    Manages the browsing history with two stacks:
    (a)s1: Holds the pages currently opened (history).
    (b)s2: Holds the pages that can be accessed by going forward after going back.
    (c)openPage: Open a new page.
    (d)next: Navigate to the next page.
    (e)prev: Navigate to the previous page.
    (f)currPage: Display the current page.
4)Main Function: Provides a user interface to interact with the browser, 
  allowing to choose actions through a menu.

*/

#include <iostream>
using namespace std;

struct node {
    string data;
    node* next;

    node(){
        next = nullptr;
    }
};

class Stack {
public:
    node* top;

    Stack(){
        top = nullptr;
    }

    void push(string s) {
        node* nn = new node;
        nn->data = s;
        nn->next = top; 
        top = nn;        
    }

    string pop() {
        if (isEmpty()) {
            cout << "Empty stack" << endl;
            return "";  
        }
        string result = top->data;  
        node* temp = top;            
        top = top->next;             
        delete temp;                
        return result;             
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return ""; 
        }
        return top->data;  
    }

    bool isEmpty() {
        if(top == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
};

class Browser {
public:
    Stack s1; 
    Stack s2; 

    void openPage(string s) {
        s1.push(s);
        cout << "User opened page: " << s << endl;
    }

    void next() {
        if (s2.isEmpty()) {
            cout << "No next page found" << endl;
            return;
        }
        s1.push(s2.pop());
        cout << "User reached page: " << s1.peek() << endl;
    }

    void prev() {
        if (s1.isEmpty()) {
            cout << "No previous page found" << endl;
            return;
        }
        s2.push(s1.pop());
        cout << "User reached page: " << s1.peek() << endl;
    }

    void currPage(){
        if (s1.isEmpty()) {
            cout << "Please Open a new page" << endl;
            return;
        }
        cout << "Currently you are on : " << s1.peek() << endl; 
    }
};

int main() {
    Browser browser;

    int p;
    while(1){

        cout << endl;
        cout << "1 -> Open New Page" << endl << " 2 -> Go to Next Page" << endl << "3 -> Go to Prev Page" << endl  <<  "4 -> Current Page "  << endl << "5 -> Exit " << endl << endl; 
        cout << "Enter Your Choics : ";
        cin >> p; 
        cout << endl;
        if(p == 1){
            string s;
            cout << "Enter Web page URL : " ;
            cin >> s;
            browser.openPage(s);
        }

        else if(p == 2){
            browser.next();
        }
        
        else if(p == 3){
            browser.prev();
        }

        else if(p == 4){
            browser.currPage();
        }

        else if(p == 5){
            break;
        }

        else{
            cout << "Enter a valid choice " << endl;
        }

    }

    return 0;
}