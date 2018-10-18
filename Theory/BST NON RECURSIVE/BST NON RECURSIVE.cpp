#include <iostream>
#include <stack>

using namespace std;

struct BST
{
	int info;
	BST *left;
	BST *right;
};

BST *root;
stack <BST *> mystack;
class binary
{
	private:
		BST *ptr,*check;
		int num;
	public:
		binary()
		{
			root = NULL;
		}
		void add()
		{
			cout<<"\nENter the number to enter in the tree and enter -1 to stop\n";
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
							if (check->left == NULL)
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
				cout<<"\nENter the number to enter in the tree and enter -1 to stop\n";
				cin>>num;
			}
		}
		
		void inorder()
		{
			ptr=root;
			do
			{
				if(ptr)
				{
					mystack.push(ptr);
					ptr=ptr->left;
				}
				else
				{
					ptr = mystack.top();
					mystack.pop();
					cout<<ptr->info;
					ptr=ptr->right;
				}
			}while(!mystack.empty() || ptr != NULL);
		}
		
		void preorder()
		{
			
			mystack.push(root);
			
			while(!mystack.empty() || ptr!=NULL)
			{
				ptr = mystack.top();
				cout<<ptr->info;
				mystack.pop();
				if(ptr->right)
				{
					mystack.push(ptr->right);
				}
				if(ptr->left)
				{
					mystack.push(ptr->left);
				}
			}
		}
		
		void find()
		{
			int snum;
			cout<<"\nEnter the number to find in the tree\n";
			cin>>snum;
			check = root;
			ptr = NULL;
			while(1)
			{
				if(check->info == snum)
				{
					cout<<"\nFOUND : ";
					if(ptr == NULL)
					{
						cout<<" Root of the tree\n";
					}
					else
					{
						cout<<ptr->info<<" is Parent\n";
					}
					break;
				}
				else if(check->info < num && check->right != NULL)
				{
					ptr = check;
					check = check->right;
				}
				else if(check->info > num && check->left != NULL)
				{
					ptr = check;
					check = check->left;
				}
				else
				{
					cout<<"\nNUMBER NOT FOUND\n";
					break;
				}
			}
		}
};

int main()
{
	binary b1;
	int cnum;
	int exit=1;
	do
	{
		cout<<"Enter 1 to add elemnts\nEnter 2 to print Inorder\nEnter 3 to print Preorder\nEnter 4 to find a number\n";
		cin>>cnum;
		switch(cnum)
		{
			case 1:
				{
					b1.add();
					break;
				}
			case 2:
				{
					cout<<"\n"<<"Inorder is : ";
					b1.inorder();
					exit = 0;
					break;
				}
			case 3:
				{
					cout<<"\n"<<"Preorder is : ";
					b1.preorder();	
					exit = 0;
					break;
				}
			case 4:
				{
					b1.find();
					exit =0;
					break;
				}
		}
	}while(exit);
	
	cout<<"\nSTART PROGRAM AGAIN TO SEE OTHER ORDER\n";
}
