#include<iostream>
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


void printLevelOrder(Node* root){
    if(root==NULL) return;

    //first create a queue and push root and NULL .
    // We are pushing nodes in queue and after poping print data of node .
    queue<Node*> q;
  q.push(root);
    q.push(NULL);

    //iterate untill queue is empty .
    while(!q.empty()){
        Node* node =q.front();
        q.pop();

        if(node != NULL){
            cout<<node->data<<" ";

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

//better
void levelOrder(Node * root) {
        if(root==NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* curr= q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }

    }

int main(){
    Node* root = new Node(1);
    root->left =new Node(2);
    root->right =new Node(3);
    root->left->left =new Node(4);
    root->left->right= new Node(5);

    root->right->left= new Node(6);
    root->right->right =new Node(7);
    printLevelOrder(root);

}