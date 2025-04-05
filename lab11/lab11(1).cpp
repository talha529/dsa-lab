#include <iostream>
using namespace std;

#define size 5

class QueueArray {
    int front, rear;
    int arr[size];

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << val << " enqueued into queue\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front++] << " dequeued from queue\n";
        if (front > rear) front = rear = -1;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QueueArray queue;
    queue.enqueue(54);
    queue.enqueue(72);
    queue.enqueue(19);
    queue.display();
    queue.dequeue();
    queue.display();
    return 0;
}

