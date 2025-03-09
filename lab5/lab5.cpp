#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayFirst() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "First Node: " << head->data << endl;
    }

    void displayLast() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        cout << "Last Node: " << temp->data << endl;
    }

    void displayNth(int n) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != NULL) {
            if (count == n) {
                cout << "Nth Node (" << n << "): " << temp->data << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Nth node does not exist!" << endl;
    }

    void displayCenter() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Center Node: " << slow->data << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    list.display();
    list.displayFirst();
    list.displayLast();
    list.displayNth(3);
    list.displayCenter();

    return 0;
}

