#include <iostream>

using namespace std;

struct BST
{
    int info;
    BST *left;
    BST *right;
};
BST *root;
class binary
{
    BST *check,*ptr;
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
    void find_l(int number)
    {
        check=root;
        while(1)
        {
            if(check->info == number)
            {
                if(check->left == NULL & check->right == NULL)
                {
                    del_leaf(ptr,check);
                }
                else if(check->left != NULL && check->right != NULL)
                {
                    ptr = check;
                    int value = del_two(check->right,ptr);
                    check->info = value;
                }
                else if(check->left!=NULL || check->right!=NULL) //if both will be null it will go in first case.
                {
                    del_singleChild(ptr,check);
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

	void find_(int number)
    {
        check=root;
        while(1)
        {
            if(check->info == number)
            {
                cout<<"Number found\n";
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

    void del_singleChild(BST *par,BST *ptr)
    {
        if(par->info >= ptr->info)
        {
            if(ptr->left!=NULL)
                par->left = ptr->left;
            else
                par->left = ptr->right;
        }
        else
        {
            if(ptr->left != NULL)
                par->right = ptr->left;
            else
                par->right = ptr->right;
        }
    }

    void del_leaf(BST *parent,BST *check)
    {
        if(parent->info < check->info)
        {
            parent->right = NULL;
        }
        else
        {
            parent->left = NULL;
        }
        delete check;
    }

    int del_two(BST *test,BST *save)
    {
        while(test->left != NULL)
        {
            save = test;
            test = test->left;
        }
        int x=test->info;
        if(test->left==NULL && test->right==NULL)
            del_leaf(save,test);
        else
            del_singleChild(save,test);
        return x;
    }

    void se_del(int num)
    {
        find_l(num);
    }

    void inorder(BST *node)
    {

        if(node == NULL)
        	return;
		inorder(node->left);
		cout<<node->info<<" ";
		inorder(node->right);
    }

     void preorder(BST *node)
    {
    	if(node == NULL)
    		return;
    	cout<<node->info<<" ";
    	preorder(node->left);
    	preorder(node->right);
	}

	void postorder(BST *node)
	{
		if(node == NULL)
			return;
		postorder(node->left);
		postorder(node->right);
		cout<<node->info<<" ";
	}
};

int main()
{
    binary b1;
    int exit = 1;
    int number,num;
    int ch;
    do
    {
        cout<<"1 to insert\n2 to find\n3 to Delete an existing element\n4 to traverse tree in inorder\n5  to traverse tree in preoder\n6  to traverse tree in postorder\n7 to exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            b1.add();
            break;
        case 2:
            cout<<"\nEnter the number to find\n";
            cin>>number;
            b1.find_(number);
            break;
        case 3:
            cout<<"\nEnter the number you want to delete\n";
            cin>>num;
            b1.se_del(num);
            break;
        case 4:
            cout<<"\nThe inorder of tree is : ";
            b1.inorder(root);
            cout<<"\n";
            break;
        case 5:
            cout<<"\nThe inorder of tree is : ";
            b1.postorder(root);
            cout<<"\n";
            break;
        case 6:
            cout<<"\nThe inorder of tree is : ";
            b1.preorder(root);
            cout<<"\n";
            break;
        case 7:
            exit = 0;
            break;
        }
    }while(exit);
}
