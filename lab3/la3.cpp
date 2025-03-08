#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node *next;
	
	
		node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};

class SingleLinkedList
{
	node *head;
	
	public:
	SingleLinkedList()
	{
		head=NULL;
	}
	void InsertAtStart(int value)
	{
	node *newNode= new node(value);
	newNode->next=head;
	head=newNode;
	display();
	}
	
	
	void InsertAtEnd(int value)
	{
		node *newNode= new node(value);
		if(head==NULL)
		{
			head=newNode;
		}
		else
		{
			node *temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
		}
		display();
		
	}

	void display()
	{
		node *temp=head;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"Null"<<endl;
	}
	
	
};
int main()
{
	
	SingleLinkedList list;
	list.InsertAtStart(2);
 	list.InsertAtStart(1);
	list.InsertAtEnd(4);
	list.InsertAtEnd(9);

	return 0;
}
