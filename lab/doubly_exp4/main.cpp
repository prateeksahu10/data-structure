#include <iostream>

using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
};

class linked
{
private:
    node *root,*tail;
    int num;
public:
    linked()
    {
        root = NULL;
    }
    void create()
    {
        cout<<"\nEnter the number to insert and -1 to stop\n";
        cin>>num;
        while(num != -1)
        {
            node *temp = new node;
            temp->info = num;
            temp->next = NULL;
            temp->prev = NULL;
            if(root == NULL)
            {
                root = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                temp->next = NULL;
                tail = temp;
            }
            cout<<"\nEnter the number to insert and -1 to stop\n";
            cin>>num;
        }
    }

    void createb()
    {
        cout<<"\nEnter the number to insert and -1 to stop\n";
        cin>>num;
        while(num != -1)
        {
            node *temp = new node;
            temp->info = num;
            temp->prev = NULL;
            temp->next = NULL;
            if(root == NULL)
            {
                root = temp;
            }
            else
            {
                temp->prev = NULL;
                temp->next = root;
                root->prev = temp;
                root = temp;
            }
            cout<<"\nEnter the number to insert and -1 to stop\n";
            cin>>num;
        }
    }

    void insertb()
    {
        int bnum,inum;
        node *ptr = new node;
        ptr = root;
        cout<<"\nEnter the number before which to insert in the linked list\n";
        cin>>bnum;
        cout<<"\nEnter which number to insert\n";
        cin>>inum;
        while(ptr != NULL)
        {
            if(ptr->info == bnum)
                break;
            ptr=ptr->next;
        }

        if(ptr->prev == NULL)
        {
            createb();
        }
        else
        {
            node * temp = new node;
            temp->info = inum;
            temp->prev = ptr->prev;
            temp->next = ptr;
            ptr->prev = temp;
            temp->prev->next = temp;
        }

    }

    void inserta()
    {
        int anum,inum;
        node *ptr = new node;
        ptr = root;
        cout<<"\nEnter the number after which to insert in the linked list\n";
        cin>>anum;
        cout<<"\nEnter which number to insert\n";
        cin>>inum;
        while(ptr != NULL)
        {
            if (ptr->info == anum)
                break;
            ptr = ptr->next;
        }

        if(ptr->next == NULL)
        {
            create();
        }
        else
        {
            node *temp = new node;
            temp->info = inum;
            temp->prev = ptr;
            temp->next = ptr->next;
            ptr->next = temp;
            temp->next->prev = temp;
        }
    }

    void display()
    {
        node *temp = root;
        cout<<"\n";
        if(temp == NULL)
        {
            cout<<"\nNo element\n";
        }
        else
        {
            while(temp != NULL)
            {
                cout<<temp->info<<" ";
                temp = temp->next;
            }
        }
        cout<<"\n";
    }

    void searche()
    {
        int snum;
        int Flag = 0;
        cout<<"\nEnter the element to search in the linked list\n";
        cin>>snum;
        node *temp = root;
        while(temp != NULL)
        {
            if(temp->info == snum)
            {
                Flag = 1;
                break;
            }
            else
            {
                Flag = 0;
            }
            temp = temp->next;
        }
        if(Flag == 1)
        {
            cout<<"\nNumber Found...\n";
        }
        else
        {
            cout<<"\nNumber Not Found...\n";
        }
    }

    void deletel()
    {
        int dnum;
        cout<<"\nEnter the number to delete in the list\n";
        cin>>dnum;
        node *ptr = new node;
        ptr = root;
        while(ptr != NULL)
        {
            if(ptr->info == dnum)
                break;
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        ptr->next = NULL;
    }
};

int main()
{
  linked l1;
  int exit = 1;
  int select;
  do
  {
      cout<<"1 to Insert a new element at the end\n2 to Insert a new element at the beginning\n3 to Insert a new element before\n4 to Insert a new element after\n5 to Delete an existing element\n6 Search an element\n7 Display all the elements\n8 to exit\n";
      cin>>select;
      switch(select)
      {
      case 1:
            l1.create();
            break;
      case 2:
            l1.createb();
            break;
      case 3:
            l1.insertb();
            break;
      case 4:
            l1.inserta();
            break;
      case 5:
            l1.deletel();
            break;
      case 6:
            l1.searche();
            break;
      case 7:
            cout<<"\nElements in Linked list are as : ";
            l1.display();
            break;
      case 8:
            exit = 0;
            break;
      }
  }while(exit);
}
