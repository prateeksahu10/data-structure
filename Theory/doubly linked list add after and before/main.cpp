#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
    node *prev;
};

class linked
{
private:
    node *root,*tail;
    int n,pos,num,innum;
public:
    linked()
    {
        root = NULL;
        tail = NULL;
    }
    void append()
    {
        cout<<"Enter the number to insert\n";
        cin>>n;
        while(n != -1)
        {
            node *temp = new node;
            if(root == NULL)
            {
            temp->data = n;
            temp->link = NULL;
            temp->prev = NULL;
            root = temp;
            tail = temp;
            }
            else
            {
                node *temp = new node;
                temp->data = n;
                temp->link = NULL;
                temp->prev = tail;
                tail->link = temp;
                tail = temp;
            }
            cout<<"Enter the number to insert\n";
            cin>>n;
        }
    }

    void add_after()
    {
        cout<<"Enter the number after which you want to insert\n";
        cin>>num;
        cout<<"Enter the number to insert\n";
        cin>>innum;

        node *ptr = new node;
        ptr = root;
        while(ptr != NULL)
        {
            if(ptr->data == num)
                break;
            ptr = ptr->link;
        }

        if(ptr->link == NULL)
        {
            last(innum,ptr);
        }
        else
        {
            node *temp = new node;
            temp->data = innum;
            temp->prev = ptr;
            temp->link = ptr->link;
            ptr->link = temp;
            temp->link->prev = temp;
        }

    }

    void last(int num,node *ptr)
    {
        ptr = tail;
        node *temp = new node;
        temp->data = num;
        temp->link = NULL;
        temp->prev = tail;
        tail->link = temp;
        tail = temp;
    }

    void add_before()
    {
        node *ptr = new node;
        ptr = root;
        cout<<"Enter the number before which you want to insert\n";
        cin>>num;
        cout<<"Enter the number to insert\n";
        cin>>innum;

        while(ptr != NULL)
        {
            if(ptr->data == num)
                break;
            ptr = ptr->link;
        }

        if(ptr->prev == NULL)
        {
            at_begin(innum);
        }
        else
        {
         node *temp = new node;
        temp->data = innum;
        temp->prev = ptr->prev;
        temp->link = ptr;
        ptr->prev = temp;
        temp->prev->link = temp;
        }
    }

    void at_begin(int num)
    {
        node *temp = new node;
        temp->data = num;
        temp->prev = NULL;
        root->prev = temp;
        temp->link = root;
        root = temp;
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
     linked l;
    int i,n,a,choice;
    l.append();
    cout<<"The list formed is\n";
    l.print();
    cout<<"Enter 1 to add after the element or 2 to enter before the element\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        l.add_after();
        l.print();
        break;

    case 2:
        l.add_before();
        l.print();
        break;

    default:
        cout<<"Wrong choice Entered\n";
        break;
    }
}
