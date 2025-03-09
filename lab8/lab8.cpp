//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//    Node(int val) {
//        data = val;
//        next = NULL;
//    }
//};
//
//class SinglyLinkedList {
//public:
//    Node* head;
//    SinglyLinkedList() {
//        head = NULL;
//    }
//
//    void insertLast(int data) {
//        Node* newNode = new Node(data);
//        if (!head) {
//            head = newNode;
//        } else {
//            Node* temp = head;
//            while (temp->next) {
//                temp = temp->next;
//            }
//            temp->next = newNode;
//        }
//    }
//
//    void display() {
//        Node* temp = head;
//        while (temp) {
//            cout << temp->data << " -> ";
//            temp = temp->next;
//        }
//        cout << "NULL" << endl;
//    }
//
//    static Node* mergeLists(Node* head1, Node* head2) {
//        if (!head1) return head2;
//        if (!head2) return head1;
//        Node* mergedHead = (head1->data < head2->data) ? head1 : head2;
//        Node* temp = mergedHead;
//        if (mergedHead == head1) head1 = head1->next;
//        else head2 = head2->next;
//        
//        while (head1 && head2) {
//            if (head1->data < head2->data) {
//                temp->next = head1;
//                head1 = head1->next;
//            } else {
//                temp->next = head2;
//                head2 = head2->next;
//            }
//            temp = temp->next;
//        }
//        temp->next = (head1) ? head1 : head2;
//        return mergedHead;
//    }
//};
//
//int main() {
//    SinglyLinkedList list1, list2;
//    list1.insertLast(1);
//    list1.insertLast(3);
//    list1.insertLast(5);
//    
//    list2.insertLast(2);
//    list2.insertLast(4);
//    list2.insertLast(6);
//
//    cout << "List 1: ";
//    list1.display();
//    cout << "List 2: ";
//    list2.display();
//
//    Node* mergedHead = SinglyLinkedList::mergeLists(list1.head, list2.head);
//    cout << "Merged List: ";
//    while (mergedHead) {
//        cout << mergedHead->data << " -> ";
//        mergedHead = mergedHead->next;
//    }
//    cout << "NULL" << endl;
//
//    return 0;
//}

#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() {
        head = NULL;
    }

    void insertLast(int data) {
        DNode* newNode = new DNode(data);
        if (!head) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    static DNode* mergeLists(DNode* head1, DNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        DNode* mergedHead = (head1->data < head2->data) ? head1 : head2;
        DNode* temp = mergedHead;
        if (mergedHead == head1) head1 = head1->next;
        else head2 = head2->next;

        while (head1 && head2) {
            if (head1->data < head2->data) {
                temp->next = head1;
                head1->prev = temp;
                temp = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2->prev = temp;
                temp = head2;
                head2 = head2->next;
            }
        }
        if (head1) {
            temp->next = head1;
            head1->prev = temp;
        } else {
            temp->next = head2;
            if (head2) head2->prev = temp;
        }
        return mergedHead;
    }
};

int main() {
    DoublyLinkedList list1, list2;
    list1.insertLast(1);
    list1.insertLast(3);
    list1.insertLast(5);
    
    list2.insertLast(2);
    list2.insertLast(4);
    list2.insertLast(6);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    DNode* mergedHead = DoublyLinkedList::mergeLists(list1.head, list2.head);
    cout << "Merged List: ";
    while (mergedHead) {
        cout << mergedHead->data << " <-> ";
        mergedHead = mergedHead->next;
    }
    cout << "NULL" << endl;

    return 0;
}

