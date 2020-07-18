#include<iostream>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 50
using namespace std;
int n,x;
class Node
{
	public:
		int data;
		Node *left;
		Node *right;
		Node()
		{
			left=NULL;
			right=NULL;
		}
};

class tree
{
	public:
		Node *root,*temp;
		tree()
		{
			root=NULL;
			temp=NULL;
		}
		
		void create();
		void insert();
		Node* search(Node* root,int value);
		void del(int n);
		void inorder_rec(Node *currentnode);
		void inorder();
		
}t;
void tree::create()
{
	char ans;
	do
	{
		cout<<"Enter value:\n";
		cin>>x;
		Node *node=new Node;
		node->data=x;
		if(root==NULL)
			root=node;
		else 
		{
			temp=root;
			while(1)
			{
				if(x>temp->data)
				{
					if(temp->right!=NULL)
					{
						temp=temp->right;
						continue;
					}
					else
					{
						temp->right=node;
						cout<<"Node added to right.\n";
						break;
					}
				}
				else
				{
					if(temp->left!=NULL)
					{
						temp=temp->left;
						continue;
					}
					else
					{
						temp->left=node;
						cout<<"Node added to left.\n";
						break;
					}
				}
			}
		}
		cout<<"If you want to enter more elements, press 'Y' else press 'N'\n";
		cin>>ans;
	}while(ans=='y'|| ans=='Y');
}
void tree::insert()
{
	char ans;
	cout<<"Enter value:\n";
	cin>>x;
	Node *node=new Node;
	node ->data=x;
	temp=root;
	if(root==NULL)
		root=node;
	else
	{
		while(1)
		{
			if(x>temp->data)
			{
				if(temp->right!=NULL)
				{
					temp=temp->right;
					continue;
				}
				else
				{
					temp->right=node;
					cout<<"Node added to right.\n";
					break;
				}
			}
			else
			{
				if(temp->left!=NULL)
				{
					temp=temp->left;
					continue;
				}
				else
				{
					temp->left=node;
					cout<<"Node added to left.\n";
					break;
				}
			}
		}
	}
}
Node* tree::search(Node* root,int value)
{
	
	if(root!=NULL)
	{
		if(root->data == value)
			return root;
		if(value < root->data)
			return(search(root->left,value));
		else
			return(search(root->right,value));
	}
	return NULL;
}
void tree::del(int n)
{
	Node *temp, *parent=NULL, *father, *r, *son;
	temp=root;
	while((temp->data!=n)&&(temp!=NULL))
	{
		if(n<temp->data)
		{
			parent=temp;
			temp=temp->left;	
		}
		else
		{
			parent=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		printf("Number not found\n");
		return;
	}
	if(temp->left==NULL)
		r=temp->right;
	else
		if(temp->right==NULL)
			r=temp->left;
	else
	{
		father=temp;
		r=temp->right;
		son=r->left;
		while(son!=NULL)
		{
			father=r;
			r=son;
			son=r->left;
		}
		if(father!=temp)
		{
			father->left=r->right;
			r->right=temp->right;
		}
		r->left=temp->left;
	}
	if(parent==NULL)
		root=r;
	else
		if(temp==parent->left)
			parent->left=r;
		else
			parent->right=r;
	delete temp;
	return;
}
void tree :: inorder_rec(Node *currentnode)
{
	if(currentnode!=NULL)
	{
		inorder_rec(currentnode->left);
		cout<<"   "<<currentnode->data;
		inorder_rec(currentnode->right);
	}
}
void tree :: inorder()
{
	inorder_rec(root);
}

int main()
{
	int ch,count;
	char choice;
	do
	{
		{
			cout<<"\n MAIN MENU";
			cout<<"\nEnter your choice\n\n1) Create\n2) Insert\n3) Search\n4)Deletion : "<<endl;
			cin>>ch;
			switch(ch)
			{
				case 1: t.create();
						break;	
				case 2: t.insert();
						break;
				case 3:
						{
							int value;
							Node *node=new Node;
							cout<<"Enter a value to be searched::";
							cin>>value; 
							node=t.search(t.root,value);
							if(node==NULL)
								cout<<"element not found";
							else
								cout<<"elemoutent found";
							break;
						}
				case 4:
						{
							int value;
							cout<<"Enter a value to be deleted::";
							cin>>value;
							t.del(value);
							t.inorder();
							break;
						}
				default:cout<<"Invalid Choice!!!";
			}
			cout<<"\nDo you want to continue:(Y|N)";
			cin>>choice;
		}
	}while(choice=='y'||choice=='Y');
	return 1;
}

