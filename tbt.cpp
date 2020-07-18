#include <iostream>
using namespace std;
class TBTNode
{
   public:
   int data,Lbit,Rbit;
   TBTNode *Left,*Right;
};
class TBTree
{
   public:
   TBTNode *curr,*temp,*Head,*Root;
//public:
   TBTree()
   {
       Root=NULL;
   }
   void create();
   void Inorder(TBTNode *);
   void Preorder(TBTNode *);
};
 
 
// Traverse a threaded tree in preorder
 
void TBTree :: Preorder (TBTNode *Root)
{
   TBTNode *temp ;
   int flag =0;
   temp =Root;
   while (temp !=Head)
   {
       if (flag == 0)
       cout<<temp->data<<" ";
       if (temp->Lbit==0 && flag==0) // go Left till Lbit is 1
       {
           temp=temp->Left;   
       }
       else
       {
           if(temp->Rbit==0) // go to Right by child
           {
               temp=temp->Right;
               flag=0;
           }
           else // go to Right by thread
           {
               temp=temp->Right;
               flag=1;
           }
       }
   }
}
void TBTree :: create( )
{
   char ans;
   int flag;
   TBTNode *node,*temp;
   Head = new TBTNode; // create head
   Head->Left=Head;
   Head->Right=Head;
   Head->Rbit=Head -> Lbit = 1;
   // create root for TBST
   Root = new TBTNode;
   cout<<endl<<"\n Enter data for root = ";
   cin >> Root -> data;
   Root->Left=Head;
   Root->Right=Head;
   // attach root to Left of Head
   Head->Left=Root;
   // make thread bit of root 0
   Root->Lbit=Root->Rbit=1;
   do
   {
       // create new node for a tree
       node = new TBTNode;
       cout <<endl<<"\n Enter next Data = ";
       cin >> node -> data;
       node->Lbit=node->Rbit = 1;
       temp = Root;
       while(1)
       {
           if(node->data<temp->data)
           {
               if(temp->Lbit==1) // checking leaf node and attach
               {
                   node->Left=temp->Left;
                   node->Right=temp;
                   // attach node to Left of temp
                   temp->Lbit=0;
                   temp->Left=node;
                   break;
               }
               else
                   temp=temp->Left;
           }
           else
           {
               if(temp->Rbit==1) // is thread
               {
                   node->Left=temp;
                   node->Right=temp->Right;
                   // attaching node to Right of temp
                   temp->Right=node;
                   temp->Rbit=0; break;
               }
               else
                   temp=temp->Right;
           }
   } // end of while
   cout<<"\n\n\t Do you want to add more data ?[y/n]";
   cin >> ans;
   }while(ans=='y'||ans=='Y');
} // end of create
 
void TBTree::Inorder(TBTNode *)
{
   TBTNode *temp;
   temp=Root;
   int flag=0;
   if(Root==NULL)
   {
       cout<<"Tree not present";
   }
   else
   {
   while(temp!=Head)
   {
   if (temp->Lbit==0 && flag==0) // go to left till Lbit is 1(till child)
   {
       temp=temp->Left;
   }
   else
   {
       cout<<temp->data<<" "; // display data
       if(temp->Rbit==0) // go to right by child
       {
           temp=temp->Right;
           flag=0;
       }
       else // go to Right by thread
       {
           temp=temp->Right;
           flag=1;
       }
   }
   }
   }
}
 
 
int main()
{
   TBTree t;
   cout<<"\n\t ********* Threaded Binary Tree **********";
   t.create();
   cout<<endl<<"\n\n\t Inorder Traversal =";
   t.Inorder(t.Root);
   cout<<endl<<"\n\n\t Preorder traversal =";
   t.Preorder(t.Root);
   return 0;
}
