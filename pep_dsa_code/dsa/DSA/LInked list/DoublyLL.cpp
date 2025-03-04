#include<iostream>
#include<cmath>
#include<list>
using namespace std;

class Node {
    public:
      int data;
      Node *next;
      Node *prev;
  
      Node(int val) {
          data = val;
          this->next = NULL;
          this->prev = NULL;
      }
  };
  class DLLNode {
    public:
      int data;
      DLLNode *next;
      DLLNode *prev;
  
      DLLNode(int val) {
          data = val;
          this->next = NULL;
          this->prev = NULL;
      }
  };

 // Deletion DLL 
Node* deleteNode(Node* head, int x) {
    // Your code here
    Node* temp =head;
    if(x==1){
        head = head->next;
        head->prev=NULL;
        delete(temp);
        return head;
    }
    for(int i=1;i<x-1 && temp->next ;i++){
        if(temp->next==NULL) break;
        temp =temp->next;
    }
    Node* del =temp->next;
    if(del->next==NULL) temp->next ==NULL;
    temp->next =del->next;
    if(del->next) del->next->prev = temp;
    delete(del);
    return head;
}

// Reversing DLL
DLLNode* reverseDLL(DLLNode* head) {
    // Your code here
    if(head==NULL || head->next==NULL) return head;
    DLLNode* temp =head;
    DLLNode* node= NULL;
    while(temp!=NULL){
        node =temp->prev;
        temp->prev= temp->next;
        temp->next=node;
        temp= temp->prev;
    }
    head=node->prev;
    return head;
    
    
}
int main(){

}