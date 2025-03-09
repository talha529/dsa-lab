#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value) {
        this->data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    node* head;

    LinkedList() {
        head = NULL;
    }

    void InsertAtPoss(int value, int poss) {
        if (poss <= 0) {  
            cout << "Invalid position!\n";
            return;
        }

        node* newNode = new node(value);

        if (poss == 1) {  // Insert at the beginning
            newNode->next = head;
            head = newNode;
            return;
        }

        node* temp = head;
        int count = 1;

        while (temp != NULL && count < poss - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position out of bounds!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.InsertAtPoss(10, 1);
    list.InsertAtPoss(20, 2);
    list.InsertAtPoss(30, 3);
    list.InsertAtPoss(15, 2);  // Insert at position 2

    cout << "Linked List:\n";
    list.display();

    return 0;
}

