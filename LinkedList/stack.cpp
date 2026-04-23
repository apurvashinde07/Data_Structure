#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


Node* top = NULL;


void push(int value){
    Node* newNode = new Node();
    if(newNode == NULL){
        cout<<"Stack Overflow\n";
        return;
    }
    newNode->data = value;

    newNode->next = top;
    top = newNode;

    cout<<value<<" inserted into stack\n";
}

void pop(){
    if(top == NULL){
        cout<<"Stack underflow\n";
        return;
    }
    Node* temp = top;
    cout<<temp->data<<"deleted from stack\n";

    top = top->next;
    delete temp;
}

void peek(){
    if(top == NULL){
        cout<<"Stack is Empty\n";
    }else{
        cout<<"top element is: "<<top->data<<endl;
    }
}

void display(){
    if(top == NULL){
        cout<<"Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout<<"Stack Element: ";
    
    while(temp != NULL){
        cout<<temp->data <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

int main(){
    int choice, value;
    do{
        cout<<".....Stack Using Linked List.....\n";
        cout<<"1.Insert element \n";
        cout<<"2.delete element\n";
        cout<<"3.Peek element\n";
        cout<<"4.display stack\n";
        cout<<"5.exit\n";

        cout<<"Enter your choice: ";
        cin>>choice;


        switch(choice){
            case 1:
            cout<<"Enter value: ";
            cin>>value;
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            cout<<"Exit\n";
            break;

            default:
            cout<<"Inalid choice\n";  
        }
    }while(choice != 5);
    return 0;

}
