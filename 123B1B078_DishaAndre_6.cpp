#include <iostream>
using namespace std;

struct node
{
    int coefficient;
    int power;
    node *next;
};

class poly{

    node *head;
    public:
    poly()
    {
        head = NULL;
    }

    void insert(int coefficient, int power)
    {
        node *nn = new node;
        if (!nn)
            return;
        nn->coefficient = coefficient;
        nn->power = power;
        nn->next = NULL;

        if (!head)
        {
            head = nn;
            return;
        }
        node* t= head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next =  nn;
        t = t->next;
        return;
    }

    void display(){
        if (!head)
        {
            cout << "No polynomial." << endl;
            return;
        }
        node *temp = head;
        cout << endl;
        while (temp)
        {
            cout << temp->coefficient << "x^" << temp->power << "+ ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }

    /* void init(){
        int choice = 1;
        node *p,*q = NULL;
        node* nn;
        int coefficient, power;
        do{
            p = head;
            nn = new node;
            if(!nn)
                return;
            cout<<"Enter coefficient and power:\n";
            cin>>coefficient>>power;

            nn->coefficient = coefficient;
            nn->power = power;
            nn->next = NULL;

            if(!head){
                head = nn;
            }
            else{
                while(p && p->power > power){
                    q = p;
                    p = p->next;
                }
                if(!q){
                    nn->next = head;
                    head = nn;
                }
                else{
                    q->next = nn;
                    nn->next = p;
                }
            }
            cout<<"More node?";
            cin>>choice;
            

        }
        while(choice == 1);
    } */

    poly operator+(poly p2){
        poly p3;
        node* q1, *q2;
        q1 = head;
        q2 = p2.head;
        while(q1 && q2){
            if(q1->power > q2->power){
                p3.insert(q1->coefficient,q1->power);
                q1 = q1->next;
            }
            else if (q1->power < q2->power){
                p3.insert(q2->coefficient,q2->power);
                q2 = q2->next;
            }
            else{
            p3.insert((q1->coefficient + q2->coefficient),q2->power);
            q1 = q1->next;
            q2 = q2->next;
        }
        }
        while(q1){
            p3.insert(q1->coefficient,q1->power);
            q1 = q1->next;
        }
        while(q2){
            p3.insert(q2->coefficient,q2->power);
            q2 = q2->next;
        }
        
    
    return p3;
    }
};


int main()
{
    poly p1,p2;

    // p1.init();
    p1.insert(12,8);
    p1.insert(7,4);
    p1.insert(3,1);

    p2.insert(10,7);
    p2.insert(7,4);
    p2.insert(12,0);
    cout<<"First polynomial:";
    p1.display();
    cout<<"\nSecond polynomial:";
    p2.display();
    
    poly p3;
    p3 = p1 + p2;
    cout<<"\nAddition:";
    p3.display();

    return 0;
}