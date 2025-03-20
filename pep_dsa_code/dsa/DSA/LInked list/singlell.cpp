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
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
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

// check palindrome
ListNode* reverseLL(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* newH = reverseLL(head->next);
    ListNode* front =head->next;
    front->next =head;
    head->next =NULL;
    return newH;
}

bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next==NULL) return true;
    ListNode* slow =head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next !=NULL){
        slow=slow->next;
        fast =fast->next->next;
    }
    ListNode* newHead =reverseLL(slow->next);
    ListNode* first =head;
    ListNode* second =newHead;
    while(second!=NULL){
        if(first->val != second->val){
            reverseLL(newHead);
            return false;
        }
        
        first= first->next;
        second =second->next;
        
    }
    reverseLL(newHead);
    return true;
}
// Remove nth from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast=head;
    ListNode* slow= head;
    for(int i=0; i<n ;i++){
        fast = fast->next;
    }
    if(fast==NULL) return head->next;
    while(fast->next !=NULL){
        slow= slow->next;
        fast= fast->next;
    }
    ListNode* delNode= slow->next;
    slow->next = delNode->next;
    delete(delNode);
    return head;
}

//ReverseLL using recursion
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead =reverseList(head->next);
    ListNode* first =head->next;
    first->next =head;
    head->next =NULL;
    return newHead;
}

// Sort LL using Merge sort
ListNode* findmiddle(ListNode* head){
    // if(head==NULL && head->next ==NULL) return head;
    ListNode* slow =head;
    ListNode* fast= head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast =fast->next->next;
    }
    return slow;
}

ListNode* mergeLL(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->val < list2->val){
            temp->next =list1;
            temp = list1;
            list1 =list1->next;               
        }
        else{
            temp->next =list2;
            temp =list2;
            list2=list2->next;
        }
    }
    if(list1) temp->next =list1;
    else temp->next =list2;
    return dummyNode->next;

}

ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* mid = findmiddle(head);
    ListNode* left =head;
    ListNode* right= mid->next;
    mid->next= NULL;
    left = sortList(left);
    right =sortList(right);
    return mergeLL(left ,right);
}

    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node* zerohead =new Node(-1);
        Node* onehead= new Node(-1);
        Node* twohead = new Node(-1);
        
        Node * zero =zerohead;
        Node* one = onehead;
        Node* two = twohead;
        Node* temp = head;
        
        while(temp!=NULL){
            if(temp->data==0){
                zero->next =temp;
                zero = temp;
            }
            else if(temp->data==1){
                one->next =temp;
                one = temp;
            }
            else{
                two->next =temp;
                two = temp;
            }
            temp =temp->next;
        }
        
        zero->next = (onehead->next)? onehead->next: twohead->next;
        one->next =twohead->next;
        two->next =NULL;
        Node* newHead =zerohead->next;
        return newHead;
    }

// Intersection of two Linked List
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL || headB==NULL) return NULL;
    ListNode* t1 =headA;
    ListNode* t2 =headB;
    while(t1!=t2){
        t1 =t1->next;
        t2 =t2->next;
        if(t1==t2) return t1;

        if(t1==NULL) t1 =headB;
        if(t2==NULL) t2=headA;
    }
    return t1;
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