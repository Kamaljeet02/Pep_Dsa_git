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
            end =temp;
        }
        size += 1;
    }

    void pop(int x){
        if(front ==NULL) return;
        
        Node *temp =front;
        front = front ->next;
        if(front==NULL) end =NULL;

        delete temp;
        size--;

    }

    int top(){
        if(front==NULL) return;
        return front ->data;
    }

};

// Queue using STACK ---->
// 1 ..1st approach
         // push --: s1 ->s2,  x->s1,   s2->s1 ;
class Q{
    public:
    stack<int> s1,s2;

    void push(int x){  //O(2N)
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        if(s1.size()==0) return;
        s1.pop();
    }
    void top(){
        if(s1.size()==0) return;
        s1.top();
    }
};
//  2nd Approach Optimal
class Q{
    public:
    stack<int>s1, s2;

    void push(int x){  //O(1)
        s1.push(x);

    }

    void pop(){
        if(!s2.empty()) s2.pop();
                //O(N) ..occasionaly
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int top(){
        if(!s2.empty()) s2.top();
                    // O(N) ...occasionaly
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
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
