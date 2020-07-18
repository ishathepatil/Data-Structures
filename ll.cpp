#include<iostream>
using namespace std;
class node
{
	public:
		 
	int data;
	node *next;
	public:
		node(int n)
		{
			data=n;
			next=NULL;
		}
};
class list
{
	node *Listptr;
	public:
		void create();
		
		void display();
			
};
void list::create()
{
	int  i,n,num;
	node *temp;
	cout<<"Enter number of nodes:\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter number:\n";
		cin>>num;
		node* newnode=new node(num);
		if(Listptr==NULL)
		{
			Listptr=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
		
	}
	cout<<"Linkedlist created\n";
}
void list::display()
{
	node *temp=Listptr;
	if(Listptr==NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL";
}
int main()
{
	int ch;
	list obj;
	cout<<"Enter your choice:\n1) Create\n2) Display\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		obj.create();
		break;
	case 2:
		obj.display();
		break;
	}
	
}
