/* insertion
deletion
searching
printing
 emptiness
*/

#include<iostream>
using namespace std;



struct Node
{
    int data;
    Node *next;
};

class LL
{
    Node *head, *current, *newNode, *last, *delNode;
    int size =0;

    public:

    void add();
    void insert(int x,int pos);
    void print();
    void remove(int x);
    void search(int x);
    void empty();
    

    LL()
    {
        head = NULL;
        current = NULL;
        newNode = NULL;
        last = NULL;
        delNode = NULL;
        

    }

    

    



};



void LL::add()
{
    size++;
    
    newNode = new Node;

    int key;

    cin>>key;

    newNode->data = key;
    newNode->next = NULL;



    if (head == NULL)
    {
        head = newNode;
        current = newNode;
        return;

    }

    
    
    current->next = newNode;
    current = current->next;
        


}

void LL::insert(int x,int pos)
{

    current = head;
    newNode = new Node;

    newNode -> data = x;
    newNode ->next = NULL;


    for(int i = 0; i<size; i++)
    {
        if(i == pos)
        {
            newNode->next = current->next;
            current->next = newNode;
            newNode = NULL;
            size++;
            return;

        }

        current = current->next;

    }

}

void LL::search(int x)
{
    current = head;

    for (int i=0; i<size ;i++ )
    {
        if(current->next->data == x)
        {
            cout<<"found the element : "<<x<<endl;
            return;
            
        }
        

        current = current-> next;
    }

    

}

void LL::remove(int x)
{
    current = head;
   search(x);
   if(current->next->next == NULL)
   {
        delNode = current->next;
        delete delNode;
        delNode = NULL;
        size--;
        return;

   }
   delNode = current->next;
   current->next = delNode->next;
   delete delNode;
   delNode = NULL;
   size--;
    





}


void LL::print()
{
    current = head;
    cout<<"{";
    for (int i = 0; i<size; i++)
    {
        cout<<current->data<<",";
        current= current->next;        
    }
    cout<<"} \n";

}

void LL::empty()
{
    if(head == NULL)
    {
        cout<<"Your list is empty. \n";
        return;
        
    }
    cout<<"list is not empty. \n";

}

int main()
{
    LL obj;
    cout<<"creating a linked list: \n"<<endl;
    cout<<"testing add function. : \n";

    cout<<"Enter your elements in linked  list : "<<endl;

    for(int i = 0 ; i<3; i++)
    {
        obj.add();

    } 

    

    
    obj.print();


    cout<<"Testing insert function : "<<endl;
    obj.insert(4,1);

    obj.print();

    cout<<"testing the search function: \n";
    obj.search(4);

    cout<<"testing the remove function: \n";
    obj.remove(4);

    obj.print();





}