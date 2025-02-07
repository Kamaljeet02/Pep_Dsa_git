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

Node* minVal(Node* root){
    Node* temp =root;
    while(temp->left!=NULL){
        temp =temp->left;
    }
    return temp;
}


Node* deleteFromBst(Node* root, int val){
    if(root == NULL) return root;

    if(root->data ==val){

        // 0 child
        if(root->left ==NULL && root->right ==NULL){
            delete root;
            return NULL;
        }


        // 1 child
        //left child
        if(root->left !=NULL && root->right ==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL&& root->right !=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child

        //either find max from LST or min from BST
        if(root->left !=NULL && root->right !=NULL){
            int mini =minVal(root->right->right)->data;
            //replacing the value
            root->data =mini;

            root->right =deleteFromBst(root->right, mini);
            return root;
        }
    }
}



int main(){
    Node* root = new Node(4);

    root->left =new Node(2);
    root->right =new Node(5);

    root->left->left =new Node(1);
    root->left->right= new Node(3);

    root->right->left= new Node(6);
    

    

}