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

int main(){

}