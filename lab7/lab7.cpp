#include <iostream>
using namespace std;

class Node
{	
	public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int value)
	{
		data=value;
		
		next=NULL;
		prev=NULL;
	}
	
};

class DoublyLinkedList
{
	
	Node *head;
	Node *tail;
	public:
	DoublyLinkedList()
	{
		
		head=NULL;
		tail=NULL;	
	
	}
	
	void insertFirst(int value)
	{
		Node *newNode= new Node(value);
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
	}
	
	void insertEnd(int value)
	{
		Node *newNode=new Node(value);
		
		if(head==NULL)
		{
			head=tail=newNode;
	
		}
		else
		{
	
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
		}
	}
	
	void insertPoss(int value, int poss)
	{
		if(poss<=0)
		{
			cout<<"Enter valid possition"<<endl;
			return;
		}
	
	
		if(poss==1)
		{
			insertFirst(value);
			return;
		}
		
		Node *newNode= new Node(value);
		Node *temp=head;
		int count=1;
		
		while(temp!=NULL&&count<poss-1)
		{
			temp=temp->next;
			count++;
		}
		
		if(temp==NULL)
		{
			cout<<"Possition out of reach! "<<endl;
		}
		
		newNode->next=temp->next;
		if(temp->next!=NULL)
		{
			temp->next->prev=newNode;
		}
		
		temp->next=newNode;
		newNode->prev=temp;
		
		if(newNode->next==NULL)
		{
			tail=newNode;
			
		}
	}
	
	void display() 
	{
	    Node* temp = head;
	    while (temp != NULL) 
		{
	        cout << temp->data << " <-> ";
	        temp = temp->next;
	    }
	    cout << "NULL\n";
	}
	
	void displayReverse() 
	{
	    Node* temp=tail;
	    while (temp !=NULL) 
		{
	        cout << temp->data << " <-> ";
	        temp = temp->prev;
	    }
	    cout << "NULL\n";
	}
	
	void insertCenter(int val) {
    if (head == NULL) {
        insertFirst(val);
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newNode = new Node(val);
    newNode->next = slow->next;
    if (slow->next != NULL) slow->next->prev = newNode;
    slow->next = newNode;
    newNode->prev = slow;

    if (newNode->next == NULL) tail = newNode;
}

};



int main() 
{
    DoublyLinkedList list;
    
    list.insertFirst(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertPoss(15, 2);
    list.insertCenter(25);

    cout << "Doubly Linked List (In Order):\n";
    list.display();

    cout << "Doubly Linked List (Reverse Order):\n";
    list.displayReverse();

    return 0;
}

