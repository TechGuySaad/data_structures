#include<iostream>

using namespace std;

class array
{
    int size = 6;
    int *arr = new int[10];
    int *current;
    int *last;
    

    public:
    array()
    {
        
        current = arr;
        cout<<"Fill up your array \n"<<endl;
        cout<<"Enter Your array size: \n";
        cin>>size;

        cout<<"Enter your array elements: \n";

        for(int i = 0; i<size; i++)
        {
            cin>>*current;
            
            current++;
        }

        current = arr;


    }
    void print();

    void start();

    void tail();

    void next();

    void back();

    void update(int x, int pos);

    void insert(int x, int pos);
    void remove(int pos);
    

    
    
    ~array()
    {
        current = NULL;
        last = NULL;
        delete [] arr;
        arr = NULL;
    }

};

void array::print()
{
    
    int *old;
    old = current;
    current = arr;
    cout<<"{";
    for (int i = 0; i<size ; i++)
    {
        cout<<*current<<",";
        current++;
    }
    cout<<"} \n";

    current = old;
}

void array:: start()
{
    current = arr;
    cout<<"the current is on: "<<*current<<" now. "<<endl;
}

void array:: tail()
{
    current = arr;
    for (int i=0;i<size;i++)
    {
        current++;
    }

    last = current;

    cout<<"the tail is on : "<<*current<<endl;
}

void array:: next()
{
    if (current == last )
    { cout<<"pointer out of bounds\n";
    return;
    }

    else {current++;}

    cout<<"current after next function: "<<*current<<endl;
    }

void array :: back()
{
    if(current == arr) 
    {cout<<"pointer out of bounds\n";
    return;
    }
    else{current--;}

    cout<<"current after back function: "<<*current<<endl;
}

void array:: update(int x, int pos)
{
    current = arr;

   

  

    for (int i = 0; i<=pos; i++)
    {
        

        if(i == pos)
        {
            *current = x;
            return;
        }

        current++;
    }
    

}

void array::insert(int x, int pos)
{
    int *mov;
    current = arr;
    size++;

    for(int i = 0; i<=size-1; i++)
    {
        
        if(i == size-1)
        {
            *current = 0;
            break;
        }
        current++;

    }
    tail();

    mov = current;
    


    for(int i=size-1 ; i>=pos; i--)
    {
        if(i == pos)
        {
            current++;
            *current = x;
            break;
        }
        current--;
        *mov = *current;
        mov--;

    }
  
}

void array:: remove(int pos)
{
    current = arr;
    if(pos == size-1)
     {
         size--;

        return;
     }

    for (int i = 0; i<size;i++)
    {
        if(i == pos)
        {
            *current = 0;
            size--;
            
            
            break;
        }
        current++;
    }
    

    int *mov;
    current = arr;
    mov = current;
    mov++;

     



    for (int i = 0; i<size; i++)
    {
       
        if(i==pos)
        {
            *current = *mov;

        }
        
        if(i>pos)
        {
        *current = *mov;
        current++;
        mov++;
        }
        
    }
    size--;



}






int main()
{
    array test;

    cout<<"-------------------\n";

    test.print();
    cout<<endl;

    cout<<"testing start: \n";
    test.start();
    cout<<endl;

    cout<<"testing tail: \n";
    test.tail();
    cout<<endl;

    cout<<"testing next(pointer out of bounds) : \n";

    test.next();
    cout<<endl;

    cout<<"testing next function without error using start function : \n";
    test.start();

    test.next();
    cout<<endl;

    cout<<"testing back function with out of bounds error using start function: \n";
    test.start();
    test.back();

    cout<<endl;

    cout<<"testing back function without the out of bounds error by using tail function \n";
    test.print();
    test.tail();
    

    test.back();
    cout<<"after backing twice : \n";
    test.back();

    cout<<endl;

    cout<<"testing update function: \n";
    
    test.update(8,5);
    test.print();

    test.start();

    cout<<endl;

    cout<<"Testing the insert function now: \n";

    test.insert(8,1);
    test.print();

    test.tail();

    cout<<"Testing the remove function: \n";

    test.remove(6);
    test.print();

    cout<<"---------------------The end------------------------------------";






    


}