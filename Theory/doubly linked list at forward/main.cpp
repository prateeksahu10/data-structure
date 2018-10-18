#include <iostream>

using namespace std;

struct node
{
    int data;
    node *prev;
    node *link;
};

class linked
{
private:
    node *root;
    node *tail;
public:
    linked()
    {
        root = NULL;
        tail = NULL;
    }
    void add_front(int n)
    {
        if(root == NULL)
        {
        node *temp = new node;
        temp->data = n;
        temp->prev = NULL;
        temp->link = NULL;
        root = temp;
        }
        else
        {
            node *temp = new node;
            temp->data = n;
            temp->prev = NULL;
            temp->link = root;
            root->prev = temp;
            root = temp;
        }
    }
    void print()
    {
        node *temp = root;
        if(temp == NULL)
        {
            cout<<"Empty";
        }
        else
        {
            while(temp != NULL)
            {
                cout<<temp->data;
                temp = temp->link;
            }
        }
    }
};

int main()
{
    linked l;
    int i,n,a;
    cout<<"Enter the number of elements to enter\n";
    cin>>n;
    cout<<"Enter the elements to enter\n";
    for(i=0;i<n;i++)
    {
        cin>>a;
        l.add_front(a);
    }
    cout<<"The list entered is after appending forward \n";
    l.print();
}
