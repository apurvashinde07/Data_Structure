#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* front = NULL;
Node* rear = NULL;


void enqueue(int value) {
    Node* newNode = new Node(value);

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted into queue\n";
}

// 🔸 DEQUEUE (Delete)
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << temp->data << " deleted from queue\n";

    front = front->next;

    
    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}


void peek() {
    if (front == NULL) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    int choice, value;

    do {
        cout << "\n--- Queue using Linked List ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}
