#include<iostream>
using namespace std;


class queue
{
    int *que, *front, *rear, *end;
    int size = 4;


    public:

    queue()
    {
        que = new int[size];
        front = NULL;
        rear = NULL;

        
        end = que;

        for(int i = 0; i<size-1; i++)
        {
            end++;

        }
    }

    void eque(int);
    
    void deque();
    void display();
};



void queue :: eque(int x)
{
    if(front == que  && rear == end)
    {
      
      cout<<"Overflow. \n";
      return;

    }

    if(front == NULL && rear == NULL)
    {
        front = que;
        rear = que;
        *rear = x;
        
        return;


    } 

    if( front != que  && rear == end )
    {
        rear = que;
        *rear = x;
        return;

    }

    if(rear + 1 == front)
    {
        cout<<"Overflow.\n";
        return;
    }

    rear++;
    *rear = x;
}


void queue:: deque()
{
    if(front == NULL && rear == NULL)
    {
        cout<<"Underflow.\n";
        return;
    }

    if(front == rear )
    {
        front = NULL;
        rear = NULL;
        return;

    }

    if(front == end)
    {
        front = que;
        return;
    }

    front++;

}


int main()
{
    queue obj;

    //obj.eque(1);
    //obj.eque(2);
    //obj.eque(3);
    //obj.eque(4);
    //obj.deque();
    //obj.deque();
    //obj.eque(5);//circular starts
    //obj.eque(6);
    //obj.eque(7); // overflow

    obj.deque();
    obj.eque(1);
    obj.deque();
    obj.eque(1);
    obj.eque(2);
    obj.eque(3);
    obj.eque(4);
    obj.eque(5);
    obj.deque();
    obj.deque();
    obj.eque(1);



    

}