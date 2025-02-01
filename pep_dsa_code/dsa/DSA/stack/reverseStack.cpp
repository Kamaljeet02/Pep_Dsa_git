#include <iostream>
#include <stack>
using namespace std;

// Function to insert element at the bottom of stack
void insertAtBottom(stack<int> &St, int element){
    if(St.empty()){
        St.push(element);
        return;
    }
    
    int topEle =St.top();
    St.pop();
    insertAtBottom(St, element);
    
    St.push(topEle);
    }
    
void Reverse(stack<int> &St){
    if(St.empty()) return;
    int topElement= St.top();
    St.pop();
    
    Reverse(St);
    insertAtBottom(St, topElement);
        
}

// Test case
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); // Stack: [1,2,3,4] (4 is at the top)


    

    return 0;
}
