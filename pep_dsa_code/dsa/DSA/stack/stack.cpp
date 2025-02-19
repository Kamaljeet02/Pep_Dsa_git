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

// MIN STACK
class MinStack {
    public:
        MinStack() {
            
        }
        stack<long long>st;
        long long mini=INT_MAX;
        void push(long long val) {
            if(st.empty()){
                mini=val;
                st.push(val);
            } 
            
            else{
                if(val>mini) st.push(val);
                else{
                    st.push(2*val-mini);
                    mini= val;
                }
            }
        }
        
        void pop() {
            if(st.empty()) return;
            long long x= st.top();
            st.pop();
            if(x<mini){
                mini =2*mini -x;
            }
        }
        
        long long top() {
            if(st.empty()) return -1;
            long long x= st.top();
            if(x<mini) return mini;
            return x;
        }
        
        long long getMin() {
            return mini;
        }
    };
    
int main(){
    stack<int> st;

}