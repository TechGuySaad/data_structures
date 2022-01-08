#include<iostream>
using namespace std;


class stack
{
    int size , *arr, top;

    public:
    void push(int x);
    void pop();
    void display();

    stack()
    {
        arr = new int[100];
        top = -1;
        size = 0;

    }


};

void stack::push(int x)
{
    if(top == -1)
    {
        arr[0] = x;

        top++;
        
        size++;

        return;

    }

    if(top == 99)
    {
        cout<<"Stack overflow\n";
        return;
    }


    
    top++;
    arr[top]=x;
    size++;


}


void stack:: pop()
{
    if(top == -1)
    {
        cout<<"stack underflow\n";
        return;
    }

    
        top--;
        size--;
        return;
        
    
}

void stack :: display()
{
    cout<<"{";
    while(top != -1)
    {
        cout<<arr[top]<<",";
        top--;
    }
    cout<<"}\n";
}






int main()
{
    stack s;

    s.push(8);
    s.push(9);

    s.display();



    s.push(8);
    s.push(9);

    s.pop();

    s.display();

    s.pop();

}