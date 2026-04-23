#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }

    Node *head = NULL;
};
Node *head = NULL;
Node *tail = NULL;

void insertionATBeginning(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        cout << "Element Inserted At the Beginning: " << val << endl;
    }
}

void insertionAtEnd(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Element Inserted At the End: " << val << endl;
}

void insertionAtSpecificPosition(int val, int pos){
    Node *newNode = new Node(val);

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;

    }else{
        Node *temp = head;
        for(int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid Postion\n";
                return;
            }
            temp=temp->next;

        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout<<"Element Inserted At sopecific Position is: "<<val<<endl;
    }

}

void deletionAtBeginning()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    cout << "Element Deleted from Linked List is: " << temp->data << endl;
    delete temp;
}

void deletionAtEnd(){
    if(head == NULL){
        cout<<"List is Empty\n";
        return;
    }
    if(head->next == NULL){
        cout<<"Element Deleted from Linked List is: "<<head->data<<endl;
        delete head;
        head = NULL;
    }else{
        Node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }
        cout<<"Element Deleted from Linked List is: "<<temp->next->data<<endl;
        delete temp->next;
        temp->next=NULL;
    }
}

void deletionAtPosition(int pos)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if (pos == 1)
    {
        deletionAtBeginning();
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }
        temp = temp->next;
    }

    Node *delNode = temp->next;

    if (delNode == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    temp->next = delNode->next;
    cout << "Deleted: " << delNode->data << endl;
    delete delNode;
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{


    int choice, value, pos;
    do
    {
        cout << "...Stack Operation....\n";
        cout << "1.Insertion At Beginning" << endl;
        cout << "2.Insertin At End" << endl;
        cout << "3.Insertin At Specific Position" <<endl;
        cout << "4.Deletion At Beginning" << endl;
        cout << "5.Deletion At End" <<endl;
        cout << "6.Dletion At specific Position" <<endl;
        cout << "7.Display Linked List" << endl;
        cout << "8.Exit\n";

        cout << "Enetr your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertionATBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertionAtEnd(value);
            break;

        case 3:
            cout<<"Enter Element and Position: ";
            cin>>value>>pos;
            insertionAtSpecificPosition(value, pos);
            break;
            

        case 4:
            deletionAtBeginning();
            break;
    

        case 5:
            deletionAtEnd();
            break;  
            
        case 6:
            cout<<"Enter Postion: ";
            cin>>pos;
            deletionAtPosition(pos);
            break;    

        case 7:
            display();
            break;

        case 8:
            cout << "...exiting....";
            break;

        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 8);

    return 0;
}