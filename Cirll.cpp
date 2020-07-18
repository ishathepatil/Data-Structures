#include<iostream>
#include<stdlib.h>

using namespace std;
class node
{
	int data;
	node *next;
	friend class list;
};
class list
{
	node *Listptr;
	node *temp;
	public:
		list()
		{
			Listptr=NULL;
			temp=NULL;
		}
		void create()
		{
			int num;
			node *temp;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			newnode->data=num;
				newnode->next=Listptr;
			if(Listptr==NULL)
			Listptr=temp=newnode;
			else
			{
				temp->next=newnode;
				temp=temp->next;
			}
		}
		void display()
		{
			node *temp=Listptr;
			while(temp->next!=Listptr)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"END\n";
		}
		void ins_beg()
		{
			int num;
			node *temp=Listptr;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			newnode->data=num;
			while(temp->next!=Listptr)
			{
				temp=temp->next;
				newnode->next=Listptr;
				Listptr=newnode;
				temp->next=newnode;
				display();	
			}
		}
};
int main()
{
	int ch;
	int ans;
	list l;
	do
	{
	cout<<"Enter choice:\n1) Create\n2) Display\n3) Insert\n";
	cin>>ch;
		switch(ch)
		{
			case 1:
				l.create();
				break;
			case 2:
				l.display();
				break;
			case 3:
				l.ins_beg();
				break;	
			default:
				cout<<"Wrong Choice\n";
		}
		cout<<"Press 0 to continue:";
		cin>>ans;
	}while(ans==0);
}
