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

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertFirst(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    }

    void insertLast(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtNth(int data, int position) {
        if (position == 1) {
            insertFirst(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        int i = 1;
        while (temp->next != head && i < position - 1) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtCentre(int data) {
        if (head == NULL) {
            insertFirst(data);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(data);
        newNode->next = slow->next;
        slow->next = newNode;
    }

    void display() {
        if (head == NULL) return;
        Node* temp = head;
        while (true) {
            cout << temp->data << " -> ";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "HEAD" << endl;
    }

    void displayReverse(Node* current, Node* start) {
        if (current == NULL) return;
        if (current->next != start) {
            displayReverse(current->next, start);
        }
        cout << current->data << " -> ";
    }

    void displayReverse() {
        if (head == NULL) return;
        displayReverse(head, head);
        cout << "HEAD" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertLast(10);
    cll.insertLast(20);
    cll.insertLast(30);
    cll.insertFirst(5);
    cll.insertAtNth(15, 3);
    cll.insertAtCentre(25);

    cout << "Circular Linked List (In Order): ";
    cll.display();

    cout << "Circular Linked List (In Reverse): ";
    cll.displayReverse();

    return 0;
}

