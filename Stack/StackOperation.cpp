#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int *arr;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push." << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }


    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;

    Stack s(n);

    int initial;
    cout << "Enter number of initial elements: ";
    cin >> initial;

    for (int i = 0; i < initial; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        s.push(value);
    }

    int choice, value;

    do {
        cout << "\nSTACK OPERATIONS MENU";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Check isEmpty";
        cout << "\n6. Check isFull";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            if (s.isEmpty())
                cout << "Stack is EMPTY." << endl;
            else
                cout << "Stack is NOT EMPTY." << endl;
            break;

        case 6:
            if (s.isFull())
                cout << "Stack is FULL." << endl;
            else
                cout << "Stack is NOT FULL." << endl;
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

