#include <iostream>

using namespace std;

class minheap
{
    public:

    int *harr, *temp, *temp1;
    int size, capacity;

    minheap()
    {
        // cout<<"Enter total capacity you want\n";
        capacity = 7;

        harr = new int[capacity];

        size = 0;
        
    }


    void insert(int key);
    void del(int key);
    int parent(int i);
    int left(int i);
    int right(int i);
    void min_heapify(int *arr);
    void print();

};

int minheap::parent(int i)
{
    int result;

    result = i - 1 / 2;
    return result;
}



void minheap::insert(int key)
{
    int i;

    if(size == capacity)
    {
        cout<<"heap overflow. \n";
        return;
    }

    if(size == 0)
    {
        harr[0] = key;
        size++;
        return;
    }

    i = size;

    harr[i] = key;
    size++;

    // cout<<"parent:"<< harr[((i-1)/2)]<<endl;
    // cout<<"right child:"<<harr[i]<<endl;

    // if(harr[((i-1)/2)] > (harr[i]) )
    // {
    //     int temp;
        

    //     temp = harr[i];
        
    //     harr[i] = harr[((i-1)/2)];
        
    //     harr[((i-1)/2)] = temp;
    //     return;
    // }

    while( i!= 0 && harr[((i-1)/2)] > (harr[i]))
    {
        int temp;
        

        temp = harr[i];
        
        harr[i] = harr[((i-1)/2)];
        
        harr[((i-1)/2)] = temp;

        i = ((i-1)/2);
    }






}

void minheap::print()
{
    for(int i = 0; i<size; i++)
    {
        cout<< harr[i]<<endl;
    }
}



int main()
{
    minheap obj;

    cout<<endl;

    obj.insert(6);
    obj.insert(7);
    obj.insert(4);
    obj.insert(3);
    obj.insert(2);
    obj.insert(1);
    obj.insert(0);
    // obj.insert(-1); //heap overflow case


    obj.print();

}