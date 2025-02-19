#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Queue using array..
class Queue{
    public:
    int *arr;

    int front;
    int rear;
    int size;
    //int currsize;

    Queue(){
        arr =new int[size];
        front =-1;
        rear =-1;
        // currsize =0;

    }
    void push(int val){
        // if(currsize ==size) return "full";
        // if(cursize==0){
        //     front =0, end=0;
        // }
        // else{
        //     end =(end+1)%size;
        // }
        if(rear==size-1){
            cout<<"Overflowww"<<endl;
            return;
        }
        rear++;
        arr[rear]= val;
        if(front==-1) front++;
        // currsize+=1;

    }

    void pop(){
        // if(cursize ==0) return "empty";
        // int ele = arr[front];
        // if(currsize== 1){
        //     curr =end =-1;
        // }
        // else start= (start+1)%size;
        // currsize -= 1;
        // return ele;

        if(front==-1){
            cout<<"Queue is empty "<<endl;
            return;
        }
        front++;
    }


};

//Queue Using LL------
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data =val;
        Node* next =NULL;
    }
};
class Queue{
    public:
    Node* front ;
    Node *end;
    int size=0;

    void push(int x){
        Node* temp= new Node(x);
        if(front==NULL){
            front = temp =end;
        }
        else{
            end->next =temp;
        }
        size += 1;
    }

    void pop(int x){
        if(front ==NULL) return;
        Node *temp =front;
        front = front ->next;
        delete temp;
        size--;

    }

    int top(){
        if(front==NULL) return;
        return front ->data;
    }
    
};
void reverseQueue(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        s.top();
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reverseQueue(q);
    
}
