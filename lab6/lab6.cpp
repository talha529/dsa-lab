#include <iostream>
using namespace std;


class Node
{
	public:
	
    int data;
    Node* next;

    Node(int val)
	{
        data = val;
        next = NULL;
    }
};

class LinkedList
{
	private:
    Node* head;

	public:
    LinkedList()
	{
        head = NULL;
    }

  
    void insert(int val)
	{
        Node* newNode = new Node(val);
        if (head == NULL) 
		{
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = newNode;
    }

   
    void display() 
	{
        if (head == NULL)
		{
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) 
		{
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    
    void deleteFirst() 
	{
        if (head == NULL) 
		{
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node deleted!" << endl;
    }

   
    void deleteLast() 
	{
        if (head == NULL) 
		{
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) 
		{
            delete head;
            head = NULL;
            cout << "Last node deleted!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) 
		{
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Last node deleted!" << endl;
    }

    
    void deleteNth(int n) 
	{
        if (head == NULL) 
		{
            cout << "List is empty!" << endl;
            return;
        }
        if (n == 1) 
		{
            deleteFirst();
            return;
        }
        Node* temp = head;
        Node* prev ;
        int count = 1;

        while (temp && count != n) 
		{
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == NULL) 
		{
            cout << "Node not found!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node " << n << " deleted!" << endl;
    }

  
    void deleteCenter() 
	{
        if (head == NULL) 
		{
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) 
		{
            delete head;
            head = NULL;
            cout << "Center node deleted!" << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) 
 {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;
        cout << "Center node deleted!" << endl;
    }
};

int main() {
    LinkedList list;

    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original List: ";
    list.display();

    list.deleteFirst();
    cout << "After deleting first node: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last node: ";
    list.display();

    list.deleteNth(2);
    cout << "After deleting 2nd node: ";
    list.display();

    list.deleteCenter();
    cout << "After deleting center node: ";
    list.display();

    return 0;
}

