#include <iostream>

using namespace std;

struct BST
{
    int info;
    BST *left;
    BST *right;
};

class binary
{
    BST *check,*root,*ptr;
    int num;
public:
    binary()
    {
        root = NULL;
    }
    void add()
    {
        cout<<"\nEnter the number until -1 is entered\n";
        cin>>num;
        while(num != -1)
        {
            BST *new_node = new BST;
            new_node->info = num;
            new_node->left = NULL;
            new_node->right = NULL;
            if(root == NULL)
            {
                root = new_node;
            }
            else
            {
                check = root;
                while(1)
                {
                    if(check->info<num)
                    {
                        if(check->right == NULL)
                        {
                            check->right=new_node;
                            cout<<"Parent is = "<<check->info<<endl;
                            break;
                        }
                        else
                        {
                            check=check->right;
                        }
                    }
                    else
                    {
                        if(check->left == NULL)
                        {
                            check->left = new_node;
                            cout<<"Parent is = "<<check->info<<endl;
                            break;
                        }
                        else
                        {
                            check=check->left;
                        }
                    }
                }
            }
            cout<<"\nEnter the number\n";
            cin>>num;
        }

    }
    void find_()
    {
        int number;
        cout<<"\nEnter the number to find\n";
        cin>>number;
        check=root;
        while(1)
        {
            if(check->info == number)
            {
                if(ptr == NULL)
                {
                    cout<<"\nIt is a root element\n";
                }
                else
                {
                    cout<<"Parent is : "<<ptr->info<<"\n";
                }
                break;
            }
            else if(check->info < number && check->info != NULL)
            {
                ptr = check;
                check = check->right;
            }
            else if(check->info >number && check->info != NULL)
            {
                ptr = check;
                check = check->left;
            }
            else
            {
                cout<<"Not Found\n";
            }
        }
    }
    void min_()
    {
        check = root;
        while(check->left != NULL)
        {
            check = check->left;
        }
        cout<<"The Minimum element in the BST is : "<<check->info<<endl<<endl;
    }
    void max_()
    {
        check = root;
        while(check->right != NULL)
        {
            check = check->right;
        }
        cout<<"The Maximum element in the BST is : "<<check->info<<endl<<endl;
    }

    void freq()
    {
        int num;
        cout<<"\nEnter the number whose frequency to find out\n";
        cin>>num;
        int Count=0;
        check=root;
        while(1)
        {
            if(check->info == num)
            {
                Count=Count+1;
                if(check->left!= NULL)
                    check=check->left;
                else
                    break;
            }
            else if(check->info >= num && check->left != NULL)
            {
                check = check->left;
            }
            else if(check->info < num && check->right != NULL)
            {
                check = check->right;
            }
            else
            {
                break;
            }
        }
        cout<<"\n"<<num<<" Occurs "<<Count<<" times in BST \n";
    }
};

int main()
{
    binary b1;
    int exit = 1;
    int ch;
    do
    {
        cout<<"1 to insert\n2 to find\n3 to find Minimum element\n4 to find Maximum element\n5 to Find the Frequency of number\n6 to exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            b1.add();
            break;
        case 2:
            b1.find_();
            break;
        case 3:
            b1.min_();
            break;
        case 4:
            b1.max_();
            break;
        case 5:
            b1.freq();
            break;
        case 6:
            exit = 0;
            break;
        }
    }while(exit);
}
