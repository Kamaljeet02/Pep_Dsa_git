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

int sumAtK(Node* root, int k){
    if(root==NULL) return -1;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level =0;
    int sum= 0;

    while(!q.empty()){
        Node* node =q.front();
        q.pop();

        if(node!=NULL){
            if(level==k) {
                sum= sum+node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }

        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;

}

int countNodes(Node* root){
    if(root==NULL) return 0;

    // int leftCount= countNodes(root->left);
    // int rightCount= countNodes(root->right);
    // return leftCount+rightCount+1;

    return countNodes(root->left) +countNodes(root->right) +1;
}

int sumOfNodes(Node* root){
    if(root==NULL) return 0;

    // int leftsum =sumOfNodes(root->left);
    // int rightsum= sumOfNodes(root->right);

    // return leftsum + rightsum + root->data;

    return sumOfNodes(root->left) + sumOfNodes(root->right) +root->data;
}

int heightOfTree(Node* root){
    if(root==NULL) return 0;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) +1;
}

void rightView(Node* root){
    if(root==NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        //we will not add NULL in queue , we will calculate the size of the queue and check how many
    //nodes are stored and traverse over it.

    int n=q.size();
    for(int i=0; i<n; i++){
        //creating a curr pointer that will start from the front of the queue.
        Node* curr =q.front();
        q.pop();

        //when we will reach at last node
        if(i==n-1){
            cout<<curr->data<<" ";
        }

        //then we will go on left and right of current node
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
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
    int ans =sumAtK(root, 3);
    cout<<ans<<endl;

}