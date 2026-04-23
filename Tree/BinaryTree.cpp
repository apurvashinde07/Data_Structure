#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(){
    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if(val == -1){
        return NULL;
    }

    Node* root = new Node(val);

    cout << "Enter left child of " << val << endl;
    root->left = buildTree();

    cout << "Enter right child of " << val << endl;
    root->right = buildTree();

    return root;
}

// Inorder Traversal
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    cout << "Build Tree:\n";
    Node* root = buildTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}