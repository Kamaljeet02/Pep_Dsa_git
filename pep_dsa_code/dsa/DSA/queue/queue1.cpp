#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// class Queue{
//     public:
//     int *arr;

//     int front;
//     int rear;
//     int size;

//     Queue(){
//         arr =new int[size];
//         front =-1;
//         rear =-1;

//     }
//     void push(int val){
//         if(rear==size-1){
//             cout<<"Overflowww"<<endl;
//             return;
//         }
//         rear++;
//         arr[rear]= val;
//         if(front==-1) front++;
//     }

//     void pop(){
//         if(front==-1){
//             cout<<"Queue is empty "<<endl;
//             return;
//         }
//         front++;
//     }


// };

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
