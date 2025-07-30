#include <iostream>
#include <cstring>
#define n 100
using namespace std;
 
class stack{
    public:
    int top;
    char arr[n];
    stack(){
    top = -1;
    }
    void push(char x){
        if(top == n-1){
            cout<<"stack is overflow"<<endl;
        }
    arr[++top] = x;
    }
    char pop(){
        if(top == -1){
            cout<<"stack is underflow"<<endl;
            return -1;
        }
        return arr[top--];
     }
    bool isEmpty(){
        return top == -1;
    }
    char peek(){
        char b = -1;
        if(top == -1){
            return b;
        }
        return arr[top];
    }
};

bool isoperator(char c){
    return (c == '+' ||  c == '-' || c == '*' || c == '/');
}

int precedence(char c){
    if(c =='*' || c == '/'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    return 0;
}

void infixtopost(char *infix ,char*postfix){
    stack s;
    int i = 0, j = 0;
    while(infix[i] != 0){
       char c = infix[i];
        if(!isoperator(c)){
            postfix[j++] = c;
        }
        else {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                postfix[j++] = s.pop();
            }
            s.push(c);
        }
        i++;
    }
    while(!s.isEmpty()){
        postfix[j++] = s.pop();
    }
    postfix[j] = 0;
 }


int main(){
    char infix[n];
    char postfix[n];
    cout<<"Enter expression:"<<endl;
    cin>>infix;
    infixtopost(infix,postfix);
    cout<<"postfix expression:"<<postfix<<endl;
    return 0;
}