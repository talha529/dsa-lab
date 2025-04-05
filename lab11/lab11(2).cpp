#include <iostream>
using namespace std;


class Node{
	
	public:
	int data;
	Node *next;
	
	Node(int value) 
	{
		data=value;
		next=NULL;	
	}
	
};


class QueueLinkedList{
	
	
	public:
	Node *front ,*rear;
	
	QueueLinkedList()
	{
		front=NULL;
		rear=NULL;
	}
	
	void enqueue(int value)
	{
			Node *newNode= new Node(value);
		if(rear==NULL)
		{
			front=rear=newNode;
			return;
		}
		
	
		
		rear->next=newNode;
		rear =newNode;	
	}
	
	
	void dequeue()
	{
		
		if(front==NULL)
		{
			
			cout<<"list is empty"<<endl;
			return;
		}
		
	Node *temp=front;
	
	front=front->next;
	
	delete temp;		
	
	if(front==NULL)
	{
		rear=NULL;
	}
	}
	
	
	void display()
	{
		if(front==NULL)
		{
			cout<<"list is empty"<<endl;
			return;
		}
		
		
		Node *temp=front;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}		
		cout<<endl;

	}
	
};

int main() 
{
	
	QueueLinkedList list;
	list.enqueue(12);
	list.enqueue(19);
	list.enqueue(10);
	list.enqueue(34);
	list.enqueue(9);
	list.display();
//	list.dequeue();
//	list.display();
	
	

	return 0;
}
