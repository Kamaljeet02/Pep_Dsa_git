#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data =val;
        next= NULL;
    }
};
void insertAtHead(Node* &head, int val){
    Node* n=new Node(val);

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next =n;
    n->next=head;
    head=n;
}

void insertAtTail(Node* &head, int val){
    Node* n =new Node(val);

    Node* temp= head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next =n;
    n->next =head;
}

void deleteHead(Node* &head){
    Node* del=head;
    Node* temp =head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;

    delete del;
}
//Floyd loop detection
Node* floydLoopDetect(Node* &head){
    if(head==NULL) return NULL;
    Node* slow=head;
    Node* fast =head;
    while(slow!=NULL &&fast!=NULL){
        slow=slow->next;
        fast= fast->next->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;

}

Node* getStartingNode(Node* &head){
    if(head==NULL) return NULL;

    Node* intersection =floydLoopDetect(head);
    Node* slow =head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    if(head==NULL) return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp=startOfLoop;

    while(temp->next!=startOfLoop){
        temp =temp->next;

    }
    temp->next =NULL;
}

int main(){

}
//delete at Kth position.
//display