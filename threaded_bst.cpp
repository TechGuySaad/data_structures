#include <iostream>
using namespace std;

struct node
{
    int info;
    node *left;
    node * right;

    int l; // will be either 1 or 0 depends on the value inside of it. Will be 1 if it is thred, will be 0 if its a child
    int r;

};

class thread
{
    // node /* *root,*/ *temp, *temp1, *dummy;

    public:

    node *root,*temp,  *dummy,*n;

    thread()
    {
        temp  = root = NULL;

        dummy = new node;

        dummy -> left = dummy;
        dummy -> right = dummy;
        dummy -> l = dummy -> r = 1;

        
    }

    void insert(int,node *);
    void del(int,node *);
    void inorder(node *);


};

node* in_s(node *temp)
{
    if(temp -> right != NULL)
    {
        temp = temp -> right;
    }

    while(temp -> l != 1)
    {
        temp = temp -> left;
    }

    return temp;


}

void thread::insert(int key, node *temp)
{
    node *temp1;
    if(root == NULL)
    {
        root = new node;
        root -> info = key;

        dummy -> left = root;  
        dummy -> l = 0;

        root -> left = dummy;// 1 is a thread
        root -> l = 1;

        root -> right = dummy; // 1 is a thread
        root -> r = 1;

        return;

        


    }

    
    
    if(key < temp-> info && temp -> l == 1)
    {
        temp1 = new node;
        temp1 -> info = key;

        temp1-> left = temp -> left;
        temp1 -> l = temp -> l;

        temp -> left = temp1;
        temp -> l = 0;

        temp1 -> right = temp;
        temp1 -> r = 1;

        return;
    }

    if(key > temp -> info && temp -> r == 1)
    {
        temp1 = new node;
        temp1 -> info = key;

        temp1 -> right = temp -> right;
        temp1 -> r = temp -> r;

        temp -> right = temp1;
        temp -> r = 0;

        temp1 -> left = temp;
        temp1 -> l = 1;

        return;
    }


    if(key < temp -> info && temp -> l == 0)
    {
        insert(key,temp->left);

    }

    if(key > temp -> info && temp -> r == 0)
    {
        insert(key,temp-> right);

    }
    
}

void thread::inorder(node *temp)
{
    while(temp -> left != dummy)
    {
        
        temp = temp -> left;
        
    }

    while(temp -> right != dummy)
    {
        
        
        cout<<temp -> info << " ";

        if(temp  == root)
        {
            if(temp -> right != NULL)
            {
                temp = temp -> right;
            }
            while(temp -> left != root)
            {
                temp = temp -> left;
                
            }

            cout<<temp -> info << " ";

        }
        


        temp = temp -> right;

        if(temp -> right == dummy)
        {
            cout<<temp -> info << " ";
        }
    }

    

    
    return;
}

void thread::del(int key, node *temp)
{
    node *temp1;
    //case 1 no children
    //non root
    if(temp -> l != 1)
    {
        if(temp -> left -> info == key)
        {
            temp1 = temp -> left;
            if(temp1 -> l == 1 && temp1 -> r == 1)
            {
                temp -> left = temp1 -> left;
                temp -> l = temp1 -> l;

                delete temp1;
                temp1 = NULL;
                return;
                

                

            }
        }


    }

    if(temp -> r != 1 )
    {
        if(temp -> right -> info == key)
        {
            temp1 = temp -> right;

            if(temp1 -> l == 1 && temp1 -> r == 1)
            {
                temp -> right = temp1 -> right;
                temp -> r = temp1 -> r;
                delete temp1;
                temp1 = NULL;
                return;

            }
        }
    }

    // root case

    //case2 one child non root
    if(temp -> l != 1 )
    {
        if(temp -> left -> info == key)
        {
            temp -> left = temp1;

            if(temp1 -> l == 0 && temp1 -> r == 1)
            {
                temp -> left = temp1 -> left;
                temp -> l = 0;

                temp1 -> left -> right = temp1 -> right;
                temp1 -> left -> r = temp1 -> r;
                return;
                

            }

            if(temp1 -> r == 0 && temp1 -> l == 1)
            {
                temp -> left = temp1 -> right ;
                temp -> l = 0;

                temp1 -> right -> left = temp1 -> left;
                temp1 -> right -> l = temp1 -> l;

                return;


            }
        }
    }

    if(temp -> r != 1)
    {
        if(temp -> right -> info == key)
        {
            temp1 = temp -> right;

            if(temp1 -> l == 0 && temp1 -> r == 1)
            {
                temp -> right = temp1 -> left;
                temp -> r = 0;

                temp1 -> left -> right = temp1 -> right;
                temp1 -> left -> r = temp1 -> r;

                delete temp1;
                temp1 = NULL;

                return;
            }

            if(temp1 -> r == 0 && temp1 -> l == 1)
            {
                temp -> right = temp1 -> right ;
                temp -> r = 0;

                temp1 -> right -> left = temp1 -> left;
                temp1 -> right ->l = temp1 -> l;

                delete temp1;
                temp1 = NULL;

                return;
            }

        }
    }



    //case3 two children non-root

    if(temp -> l != 1)
    {
        if(temp -> left -> info == key)
        {
            temp1 = temp -> left;
            if(temp1 -> l == 0 && temp1 -> r == 0)
            {
                n = in_s(temp1);

                temp1 -> info = n -> info;
                

                del(n->info,temp1);
                return;


            }
        }

    }

    if(temp -> r != 1)
    {
        if(temp -> right -> info == key)
        {
            temp1 = temp -> right;
            if(temp1 -> l == 0 && temp1 -> r == 0)
            {
                n = in_s(temp1);

                temp1 -> info = n -> info;

                del(temp1 -> info,temp1);
                return;
                
            }
        }

    }











    if(key < temp -> info && temp -> l == 0)
    {
        del(key,temp -> left);

    }

    if(key > temp -> info && temp -> r == 0)
    {
        del(key, temp -> right);
    }
}


int main()
{
    thread obj;

    obj.insert(20,obj.root);
    obj.insert(15,obj.root);
    obj.insert(30,obj.root);
    obj.insert(10,obj.root);
    obj.insert(17,obj.root);    
    obj.insert(25,obj.root);
    obj.insert(31,obj.root);

    obj.del(30,obj.root);

    // node *t = in_s(obj.root -> left);
    // cout<< t-> info;

    
    
    obj.inorder(obj.root); 
    cout<<endl;

    





}