#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	int data;
	node *left;
	node *right;
	friend class tree;
};
class tree
{
	node *root;
	public:
		tree()
		{
			root=NULL;
		}
		void create()
		{
			int num;
			char ans;
			node *temp;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			newnode->data=num;
			
			if(root==NULL)
			{
				root=newnode;
			}
			else
			{
				temp=root;
				while(1)
				{
					cout<<"Left or Right (l/r):";
					cin>>ans;
					if(ans=='l')
					{
						if(temp->left==NULL)
						{
							temp->left=newnode;
						}
						else
						{
							temp=temp->left;
						}
					}
					else
					{
						if(temp->right==NULL)
						{
							temp->right=newnode;
						}
						else
						{
							temp=temp->right;
						}
					}
				}
			}
		}
		void display()
		{
			node *temp;
			if(root==NULL)
			{
				cout<<"Tree does not exist.\n";
			}
			else
			{
				temp=root;
				cout<<"root:"<<temp->data<<"\n";
				while(temp->left!=NULL)
				{
					cout<<"left:"<<temp->data<<"-";
					temp=temp->left;
				}
				cout<<temp->data;
				cout<<"END\n";
				while(temp->right!=NULL)
				{
					cout<<"right:"<<temp->data<<"-";
					temp=temp->right;
				}
				cout<<temp->data;
				cout<<"END\n";
			}
		}
};
int main()
{
	int ch;
	int ans;
	tree t;
	do
	{
		cout<<"Enter Choice.\n1) Create\n2) Display\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				t.create();
				break;
			case 2:
				t.display();
				break;
			default:
				cout<<"Wrong Choice.\n";
		}
		cout<<"Press 0 to continue, else 1\n";
		cin>>ans;
	}
	while(ans==0);
	
}

