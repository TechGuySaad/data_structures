#include <iostream>
using namespace std;

struct node 
{
    node *next;
    int info;

};

class stack
{
    node *top, *newNode;

    public:

    stack()
    {
        top = NULL;
        newNode = NULL;
    }

    void push(int);
    void pop();
    void print();
    

};

void stack :: push(int x)
{
    newNode = new node;

    newNode ->info = x;
    newNode -> next = NULL;

    if(top == NULL)
    {
        
        top = newNode;
        return;
    }

    newNode -> next = top;
    top = newNode;
    
    




}

void stack:: pop()
{
    if(top == NULL)
    {
        cout<<"Stack underflow. \n ";
        return;
    }

    if(top -> next == NULL)
    {
        delete top;
        top = NULL;
        newNode = NULL;
        return;
    }

    top = newNode -> next;
    delete newNode;
    newNode = top;

}

void stack :: print()
{
    node * printer;

    printer = top;
    cout<<"stack values: ";

    while(printer != NULL)
    {
        cout<<printer->info <<" ";
        
        printer = printer -> next;


        if(printer-> next == NULL)
        {
            cout<<printer->info<<endl;
            return;
        }
        
        

    }


}

int main()
{
    stack obj;

    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.print();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.print(); // stack is empty here
    cout<<endl;
    obj.pop(); // popping out of an empty stack


}