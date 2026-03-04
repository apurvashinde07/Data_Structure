#include <iostream>
using namespace std;

class Queue {
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert." << endl;
        } else {
            if (front == -1)
                front = 0;
            arr[++rear] = value;
            cout << value << " inserted into queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot delete." << endl;
        } else {
            cout << arr[front++] << " deleted from queue." << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter size of queue: ";
    cin >> n;

    Queue q(n);

    int initial;
    cout << "Enter number of initial elements: ";
    cin >> initial;

    for (int i = 0; i < initial; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        q.enqueue(value);
    }

    int choice, value;

    do {
        cout << "\nQUEUE OPERATIONS MENU";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Check isEmpty";
        cout << "\n6. Check isFull";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is EMPTY." << endl;
            else
                cout << "Queue is NOT EMPTY." << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is FULL." << endl;
            else
                cout << "Queue is NOT FULL." << endl;
            break;

        case 7:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
