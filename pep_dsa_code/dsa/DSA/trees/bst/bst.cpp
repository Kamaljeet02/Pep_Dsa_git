#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data= val;
        left =NULL;
        right = NULL;
    }
};



Node* searchBst(Node* root, int key){
    if(root==NULL) return NULL;

    if(root->data ==key) return root;
    // if(root->data < key) return searchBst(root->right, key);
    if(root->data > key) return searchBst(root->left, key);

    return searchBst(root->right ,key);
    
}

Node* minVal(Node* root){
    Node* temp =root;
    while(temp->left!=NULL){
        temp =temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp =root;
    while(temp->right!=NULL){
        temp= temp->right;
    }
    return temp;
}

int main(){
    Node* root = new Node(4);

    root->left =new Node(2);
    root->right =new Node(5);

    root->left->left =new Node(1);
    root->left->right= new Node(3);

    root->right->left= new Node(6);
    

    

}