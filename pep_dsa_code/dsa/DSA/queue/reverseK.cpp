#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> kReversal(queue<int> q, int k){
    stack<int>s;
    queue<int>q1;
    int n=q.size();
    for(int i=0;i<n;i++){
        int temp=q.front();
        q.pop();
        s.push(temp);
    }
    for(int i=0;i<k;i++){
        if(s.empty()){
            break;
        }
        q1.push(s.top());
        s.pop();
    }
    while(!s.empty()){
        q1.push(s.top());
        s.pop();
    }
    return q1;

}

queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    stack<int> st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        // int ele =st.top();
        // st.pop();
        q.push(st.top());
        st.pop();
        
        
    }
    return q;
    
}

void deleteFromStack(stack<int>&inputStack, int count, int size){
   if(inputStack.empty() || count==size/2){
      inputStack.pop();
      return;
   }
   int temp=inputStack.top();
   inputStack.pop();

   deleteFromStack(inputStack, count+1, size);
   inputStack.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count =0;
   deleteFromStack(inputStack, count, N);

   
}

int main(){

}