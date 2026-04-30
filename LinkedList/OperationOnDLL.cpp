#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Inserted at Beginning: " << val << endl;
}

void insertAtEnd(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Inserted at End: " << val << endl;
}


void insertAtPosition(int val, int pos) {
    Node* newNode = new Node(val);

    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        insertAtEnd(val);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Inserted at Position: " << val << endl;
}


void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}


void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Deleted: " << temp->data << endl;

    temp->prev->next = NULL;
    delete temp;
}


void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void displayForward() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;
    cout << "Forward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


void displayBackward() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node* temp = head;


    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}


int main() {
    int choice, value, pos;

    do {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cin >> value >> pos;
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                cin >> pos;
                deleteAtPosition(pos);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}
