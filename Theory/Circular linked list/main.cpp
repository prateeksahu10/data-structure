#include <iostream>
using namespace std;
struct node
{
    int num;
    node *next;
};


node * head = NULL;
node * tail= NULL;
void append(int num)
{
    node *temp = new node;
    temp->num = num;
    if(head == NULL)
    {
        temp->next = head;
        head =temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        tail->next = temp;
        head = temp;

    }
}

void append_l(int num)
{
    node *temp = new node;
    temp->num = num;
    if(head == NULL)
    {
        temp->next = head;
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        tail->next = temp;
        tail = temp;
    }
}

void print()
{
    node *temp= head;
    do{
        cout<<temp->num<<"->";
        temp = temp->next;
    }while(temp != head);
    cout<<temp->num;
}

int main()
{
    cout<<"**************CIRCULAR LINKED LIST************\n";
    int n;
    cout<<"Enter the number of elements to enter in the list\n";
    cin>>n;
    int num;
    int ch;
    cout<<"Enter 1 to add at front and 2 to add at last\n";
    cin>>ch;
    if(ch == 1)
    {
        cout<<"Enter the elements\n";
        for(int i=0;i<n;i++)
        {
            cin>>num;
            append(num);
        }
    }
    else
    {
        cout<<"Enter the elements\n";
        for(int i=0;i<n;i++)
        {
            cin>>num;
            append_l(num);
        }
    }
    cout<<"The elements in the list are :\n";
    print();
}
