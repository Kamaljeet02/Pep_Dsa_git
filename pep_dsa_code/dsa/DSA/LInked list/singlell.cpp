#include <iostream>

// #include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;;
        next = NULL;
    }
};

void insertAtTail(Node* &head , int val){
    Node* n =new Node(val);

    if(head==NULL){
        head =n;
        return;
    }

    Node* temp= head;
    while(temp->next != NULL){
        temp =temp->next;
    }
    temp->next = n;
}

void insertAtHead(Node* &head, int val){
    Node* n= new Node(val);
    n->next =head;
    head =n;
}

void display(Node* head){
    Node* temp =head;
    while(temp!=NULL){
        cout<< temp->data <<" -> ";
        temp =temp->next;
    }
    cout<<"NULL"<<endl;
}
bool search(Node* &head, int key){
    Node* temp= head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp =temp->next;
    }
    return false;

}

void deeletion(Node* &head, int val){
    Node* temp =head;

    if(head==NULL) return;

    while(temp->next->data != val){
        temp= temp->next;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void deleteHead(Node* &head){
    Node* temp =head;
    head =head->next;
    delete temp;
}

Node* reverseLL(Node* &head ){
    
    Node* prev =NULL;
    Node* curr=head;
    Node* nxt=curr->next;
    while(curr!=NULL){
        nxt =curr->next;
        curr->next =prev;

        prev=curr;
        curr=nxt;
    }
    head =prev;
    return head;
}

//check again (wrong)
Node* kReversal(Node* &head, int k){
    //prev, nxt , curr will be same 
    //make a count var to count till k;
    Node* prev=NULL;
    Node* curr=head;
    Node* nxt=curr->next;
    int count=0;
    while(curr!=NULL && count<k){
        nxt=curr->next;
        curr->next=prev;
        prev =curr;
        curr=nxt;
        count++;
    }
    
    if(nxt!=NULL){
        head->next=kReversal(nxt, k);
    }
    return prev;
    

}

int main() {
    Node *head =NULL;
    insertAtHead(head ,1);
    insertAtHead(head,2);
    insertAtHead(head,4);
    insertAtHead(head,5);
    display(head);
    return 0;
}
//find middle 