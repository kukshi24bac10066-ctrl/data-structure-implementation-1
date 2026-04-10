#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];   // Array to store elements
    int front, rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) front = 0;

        arr[++rear] = value;
        cout << value << " inserted into queue\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed from queue\n";
        front++;

        // Reset queue when empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Peek operation
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front element is: " << arr[front] << endl;
    }

    // Display queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();
    q.display();

    return 0;
}