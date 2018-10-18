#include<iostream>

using namespace std;

struct BST
{
	int info;
	BST *right;
	BST *left;
};

BST *root;
class binary
{
	private:
		BST *check;
		int num;
	public:
		binary()
		{
			root = NULL;
		}	
		void add()
		{
			cout<<"\nEnter the number to insert in the tree\n";
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
								check->right = new_node;
								cout<<"\n"<<check->info<<" Parent\n";
								break;
							}
							else
							{
								check = check->right;
							}
						}
						else
						{
							if(check->left == NULL)
							{
								check->left = new_node;
								cout<<"\n"<<check->info<<" Parent\n";
								break;
							}
							else
							{
								check = check->left;
							}
						}
					}
				}
				cout<<"\nEnter the number to insert in the tree\n";
				cin>>num;
			}
		}
		
	void inorderl(BST *node)
    {

        if(node == NULL)
        	return;
		inorderl(node->left);
		cout<<node->info;
		inorderl(node->right);
    }
    
    void preorder(BST *node)
    {
    	if(node == NULL)
    		return;
    	cout<<node->info;
    	preorder(node->left);
    	preorder(node->right);
	}
	
	void postorder(BST *node)
	{
		if(node == NULL)
			return;
		postorder(node->left);
		postorder(node->right);
		cout<<node->info;
	}
    
};

int main()
{
	binary b1;
	int num;
	int exit=1;
	do
	{
		cout<<"Enter 1 to add elemnts\nEnter 2 to print Inorder\nEnter 3 to print Preorder\nEnter 4 to print Postorder\n";
		cin>>num;
		switch(num)
		{
			case 1:
				{
					b1.add();
					break;
				}
			case 2:
				{
					cout<<"\n"<<"Inorder is : ";
					b1.inorderl(root);
					exit = 0;
					break;
				}
			case 3:
				{
					cout<<"\n"<<"Preorder is : ";
					b1.preorder(root);	
					exit = 0;
					break;
				}
			case 4:
				{
					cout<<"\n"<<"Postorder is : ";
					b1.postorder(root);
					exit = 0;
					break;
				}	
		}
	}while(exit);
	
	cout<<"\nSTART PROGRAM AGAIN TO SEE OTHER ORDER\n";
}
