#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	int data;
	node *next;
	friend class list;
};
class list:public node
{
	node *Listptr;
	node *temp;
	public:
	list()
	{
		Listptr=NULL;
		temp=NULL;
	}
	public:
		void create()
		{
			int num;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			newnode->data=num;
			newnode->next=NULL;
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
			if(temp==NULL)
			{
				cout<<"List is empty";
			}
			while(temp!=NULL)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL\n";
		}
		void length()
		{
			node *temp=Listptr;
			int count=0;
			while(temp)
			{
				temp=temp->next;
				count++;
			}
			cout<<"Length:"<<count<<"\n";
		}
		void ins_beg()
		{
			int num;
			node *temp;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			newnode->data=num;
			if(Listptr==NULL)
			Listptr=newnode;
			else
			{
				newnode->next=Listptr;
				Listptr=newnode;
			}
		}
		void ins_end()
		{
			int num;
			node *temp;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			newnode->data=num;
			newnode->next=NULL;
			temp=Listptr;
			if(Listptr==NULL)
			{
				cout<<"List is empty";
			}
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
		void ins_middle()
		{
			int num,pos;
			int count=1;
			node *temp;
			node *newnode=new node;
			cout<<"Enter number:";
			cin>>num;
			cout<<"Enter position";
			cin>>pos;
			while(count!=pos)
			{
				temp=Listptr;
				temp=temp->next;
				count++;
			}
			if(count==pos)
			{
				newnode->data=num;
				newnode->next=temp->next;
				temp->next=newnode;
			}
			else
			cout<<"Range not found.\n";
		}
		void del_beg()
		{
			node *temp=Listptr;
			Listptr=temp->next;
			free(temp);
			display();
		}
		void del_end()
		{
			node *temp=Listptr;
			node *temp1;
			if(temp->next!=NULL)
			{
				temp=temp->next;
			}
				temp1=temp->next;
				free(temp1);
				temp->next=NULL;
				display();
			
		}
		void del_middle()
		{
			int pos,count=1;
			node *temp=Listptr;
			node *temp1;
			cout<<"Enter position to delete from:";
			cin>>pos;
			if(count!=pos)
			{
				temp=temp->next;
				count++;
			}
			temp1=temp->next;
			temp->next=temp1->next;
			free(temp1);
			display();
			
		}
		void search()
		{
			int pos=1,val;
			node *temp=Listptr;
			cout<<"Enter the value you want to search:";
			cin>>val;
			if(temp->next->data==val)
			{
				cout<<"Value found at:"<<pos<<"\n";
			}
			else 
			{
				temp=temp->next;
				pos++;
			}
		}
			void reverse()
		{
			node * forward, *curr, *back;
			forward= Listptr;
			curr =NULL;
		
			while(forward!=NULL)
			{
				back = curr;	
				curr = forward;
				forward = forward->next;
				curr->next = back;
			}
			Listptr= curr;
			display();
		}
};
int main()
{
	int ch,c;
	int ans;
	list l;
	do
	{
	cout<<"Enter choice:\n1) Create\n2) Display\n3) Length\n4) Insert\n5) Delete\n6) Search\n7) Reverse\n";
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
				l.length();
				break;	
			case 4:
				cout<<"Enter choice\n1) Insert at beginning\n2) Insert at end\n3) Insert in the middle\n";
				cin>>c;
				switch(c)
				{
					case 1:
						l.ins_beg();
						break;
					case 2:
						l.ins_end();
						break;
					case 3:
						l.ins_middle();
						break;	
					default:
						cout<<"Wrong choice.\n";
				}
				break;
			case 5:
				cout<<"Enter choice\n1) Delete from beginning\n2) Delete from end\n3) Delete from middle\n"	;
				cin>>c;
				switch(c)
				{
					case 1:
						l.del_beg();
						break;
					case 2:
						l.del_end();
						break;	
					case 3:
						l.del_middle();
						break;	
				}
				break;
			case 6:
				l.search();
				break;
			case 7:
				l.reverse();
				break;	
			default:
				cout<<"Wrong choice.\n";
			
		}
		cout<<"Press 0 to continue:";
		cin>>ans;
	}
	while(ans==0);
}

