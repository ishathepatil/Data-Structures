#include<iostream>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int n,x;
class Node
{
	public:
		int data;
		Node *next;
		Node *prev;
};

class list:public Node
{
	public:
		Node *lptr,*temp;
		list()
		{
			lptr=NULL;
			temp=NULL;
		}
		void create();
		void display();
		void length();
		void insert_beg();
		void insert_mid();
		void insert_end();
		void del_beg();
		void del_mid();
		void del_end();
		void del_val();
		void reverse();
		void concat(list);
		void Union(list);
		void intersec(list);
}l,l2;

void list::create()
{
	int n,x;
	cout<<"Enter number of nodes you want to create: ";
	cin>>n;
	cout<<"Enter "<<n<<" values:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		Node *newnode=new Node;
		newnode->data=x;
		newnode->next=NULL;
		if(lptr==NULL)
		{
			lptr=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
}
void list::display()
{
	if(lptr==NULL)
	cout<<"List Empty!";
	else
	{
	temp=lptr;
	cout<<"NULL->";
	while(temp->next!=NULL)
	{
		cout<<temp->data<<" <-> ";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<" <-> NULL";
	}
}
void list::length()
{
	int l=1;
	temp=lptr;
	if(lptr==NULL)
	cout<<"List is empty!";
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
			l++;
		}
		cout<<"Length of string is "<<l<<".";
	}
}
void list::insert_beg()
{
	Node *newnode=new Node; 
	cout<<"Enter value: ";
	cin>>x;
	newnode->data=x;
	newnode->next=lptr;
	lptr=newnode;
}
void list::insert_mid()
{
	Node *newnode=new Node;
	temp=lptr;
	int i;
	cout<<"Enter position of new element: ";
	cin>>n;
	for(i=1;i<n-1 && temp->next!=NULL;i++)
	temp=temp->next;
	if(i<n-1)
	{
		cout<<"Position out of range!";
		delete newnode;
	}
	else
	{
		cout<<"Enter value: ";
		cin>>x;
		newnode->data=x;
		newnode->next=temp->next;
		temp->next->prev=newnode;
		newnode->prev=temp;
		temp->next=newnode;
	}
}
void list::insert_end()
{
	Node *newnode=new Node;
	temp=lptr;
	cout<<"Enter value: ";
	cin>>x;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newnode;
	newnode->data=x;
	newnode->prev=temp;
	newnode->next=NULL;
}
void list::del_beg()
{
	temp=lptr;
	lptr=lptr->next;
	cout<<temp->data<<" is deleted.";
	delete temp;
}
void list::del_mid()
{
	temp=lptr;
	int i;
	cout<<"Enter position of element to be deleted: ";
	cin>>n;
	for(i=1;i<n && temp->next!=NULL;i++)
	temp=temp->next;

	if(i<n-1)
	cout<<"Position out of range!";
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		cout<<temp->data<<" is deleted.";
		delete (temp);
	}
}
void list::del_end()
{
	temp=lptr;
	while(temp->next->next!=NULL)
	temp=temp->next;
	cout<<temp->next->data<<" is deleted.";
	delete temp->next;
	temp->next=NULL;
}
void list::del_val()
{
	temp=lptr;
	Node *q;
	cout<<"Enter value at node to be deleted: ";
	cin>>x;
	if(temp->data==x)
	{
		lptr=temp->next;
		cout<<x<<" is deleted.";
		delete temp;
	}
	else
	{
		while(temp->next->data!=x && temp->next!=NULL)
		temp=temp->next;
		if(temp->next==NULL)
		cout<<"Element not found!";
		else
		{
			q=temp->next;
			temp->next=q->next;
			cout<<x<<" is deleted.";
			delete q;
		}
	}
}
void list::reverse()
{
	temp=lptr;
	while(temp->next!=NULL)
	temp=temp->next;
	cout<<"The reversed linked list is:\n";
	while(temp->prev!=lptr)
	{
		cout<<temp->data<<" <-> ";
		temp=temp->prev;
	}
	cout<<temp->data<<" <-> ";
	cout<<lptr->data<<" <-> NULL ";
	lptr->prev=NULL;
	
	
}
void list::concat(list l2)
{
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=l2.lptr;
	l2.lptr->prev=temp;
	cout<<"\nThe concatenated list is:\n";
	display();
	
	Node *temp2;
	for(temp=lptr;temp->next!=NULL;temp=temp->next)
	{
		for(temp2=temp->next;temp2!=NULL;temp2=temp2->next)
		{
			if(temp->data>temp2->data)
			{
				x=temp->data;
				temp->data=temp2->data;
				temp2->data=x;
			}
		}
	}
	cout<<"\n\nThe sorted list is:\n";
	display();
}

void list::Union(list l2)
{
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=l2.lptr;
	cout<<"\nThe concatenated list is:\n";
	display();
	
	Node *temp2;
	for(temp=lptr;temp->next!=NULL;temp=temp->next)
	{
		for(temp2=temp->next;temp2!=NULL;temp2=temp2->next)
		{
			if(temp->data>temp2->data)
			{
				x=temp->data;
				temp->data=temp2->data;
				temp2->data=x;
			}
		}
	}
	cout<<"\n\nThe sorted list is:\n";
	display();
	cout<<"\n\nThe union list is:\n";
	temp=lptr;
	cout<<"NULL->";
	cout<<temp->data<<" <-> ";
	while(temp->next!=NULL)
	{
		if(temp->data!=temp->next->data)
		{
			cout<<temp->next->data<<" <-> ";
		
		}
			temp=temp->next;
	}
	cout<<"NULL";
}

void list::intersec(list l2)
{
	int l,flag;
	for(l=1,temp=lptr;temp->next!=NULL;l++,temp=temp->next);
	Node *temp3,*temp2=l2.lptr;
	cout<<"The intersection of two lists is:\n";
	while(temp2!=NULL)
	{
		temp3=lptr;
		flag=0;
		for(int i=0;i<l;i++)
		{
			if(temp2->data==temp3->data)
			{
				flag++;
				break;
			}
			temp3=temp3->next;
		}
		if(flag!=0)
		{
			cout<<temp2->data<<" <-> ";
		}
		if(temp2->next!=NULL)
		{
			while(temp2->data==temp2->next->data)
			temp2=temp2->next;
		}
		temp2=temp2->next;
	}
	cout<<"NULL";	
}

int main()
{
	int ch;
	while(1)
	{
		
		cout<<"\n            MAIN MENU";
		cout<<"\n1. Create\n2. Display\n3. Length of Linked List\n4. Insert at beginning \n5. Insert at Middle \n6. Insert at End \n7. Delete from Beginning \n8. Delete from Middle \n9. Delete from End \n10.Delete specific value \n11.Concatinate two Lists and Sort the concatenated list \n12.Reverse Linked List\n13.Union of two Linked Lists\n14.Intersection of two Linked Lists\n15.Exit\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: l.create();
					break;
			case 2: l.display();		
					break;
			case 3: l.length();
					break;
			case 4:	l.insert_beg();
					break;
			case 5:	l.insert_mid();
					break;
			case 6:	l.insert_end();
					break;
			case 7: l.del_beg();
					break;
			case 8:	l.del_mid();
					break;
			case 9: l.del_end();
					break;
			case 10:l.del_val();
					break;
			case 11:l2.create();
					l.concat(l2);			
					break;
			case 12:l.reverse();
					break;
			case 13:l2.create();
					l.Union(l2);
					l2.lptr=NULL;			
					break;
			case 14:l2.create();
					l.intersec(l2);
					l2.lptr=NULL;
					break;				
			case 15:exit(0);
					
		}
		cout<<"\n\nPress any key to continue...";
		getch();
	}
}

