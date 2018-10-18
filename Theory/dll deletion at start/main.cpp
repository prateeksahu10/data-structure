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
    node *root,*tail;
public:
    linked()
    {
        root = NULL;
        tail = NULL;
    }
    void append(int num)
    {
        if(root == NULL)
            {
                node *temp = new node;
                temp->data = num;
                temp->link = NULL;
                temp->prev = NULL;
                root = temp;
                tail = temp;
            }
        else
        {
            node *temp = new node;
            temp->data = num;
            tail->link = temp;
            temp->prev = tail;
            temp->link  = NULL;
            tail=temp;
        }
    }

    void delete_beg()
    {
        node * temp;
        temp = root;
        root = temp->link;
        temp->link->prev = NULL;
        temp->link  = NULL;
        delete temp;
    }

    void print()
    {
        node *temp = root;
        if(temp == NULL)
        {
            cout<<"Empty\n";
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
    linked l1;
    int n,a;
    cout<<"Enter the number of element\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>a;
        l1.append(a);
    }
    l1.print();
    int num;
    l1.delete_beg();
    cout<<"\nThe deleted array become\n";
    l1.print();
}
