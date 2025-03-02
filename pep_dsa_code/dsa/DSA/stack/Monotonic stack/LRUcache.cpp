#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(){
        next=NULL;
        prev=NULL;
    }
    Node(int k, int v){
        key =k;
        data =v;
        next =NULL;
        prev= NULL;
    }

};

class LRUCache {
public:
    map<int , Node*> mpp;
    int cap;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        cap =capacity;
        head =new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next =tail;
        tail->prev =head;

    }
    
    void insertAtHead(Node* node){
        Node* headNxt=head->next;
        head->next= node;
        node->next = headNxt;
        node->prev =head;
        headNxt->prev =node;
    }

    void deleteNode(Node* node){
        Node* prevNode =node->prev;
        Node* nxt= node ->next;
        prevNode ->next= nxt;
        nxt->prev =prevNode;
    }

    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node =mpp[key];
            deleteNode(node);
            insertAtHead(node);
            return node->data;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->data = value;
            deleteNode(node);
            insertAtHead(node);
        }
        else{
            if(mpp.size()== cap){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node=new Node(key , value);
            insertAtHead(node);
            mpp[key]=node;
        }
    }
};

int main(){

}