#include<iostream>

using namespace std;
//using array---
class MyStack{
    public:
    int *arr;
    int top;
    int size;

    MyStack(){
        arr= new int[size];
        top=-1;
    }
    void push(int val){
        if(top==-size-1){
            cout<<"stack overflow";
            return;
        }
        top++;
        arr[top]=val;
    }

    void pop(){
        if(top==-1) return;
        top--;
    }

    bool isEmpty(){
        if(top==-1) return true;
        else return false;
    }

    int peek(){
        if(top=-1)return -1;
        else return arr[top];
    }
};

//using linked list-------
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data =val;
        next =NULL;
    }
};
class Stack{
    public:;
    Node* top;
    int size=0;
    void push(int x){
        Node* temp =new Node(x);
        temp->next =top;
        top =temp;
        size ++; 
    }

    void pop(){
        Node* temp =top;
        top = top->next;
        delete temp;
        size--;
    }
};

//Stack using  QUEUE -----
class Stack{
    public:
    queue<int> q;
    int s=q.size();

    void push(int x){
        q.push(x);
        for(int i =1; i<=s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        q.pop();
    }

    int top(){
        return q.front();
    }
};
int main(){
    stack<int> st;

}