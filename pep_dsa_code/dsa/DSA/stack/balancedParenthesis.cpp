#include<iostream>
#include<stack>
using namespace std;

bool balancedParenthesis(string str){
    stack<char> st;
    bool ans =true;
    for(int i=0; i<str.length();i++){

        if(str[i]=='{' ||str[i]=='[' ||str[i]=='('){
            st.push(str[i]);

        }
        if(st.empty()) return false;
        else if(str[i]==')'){
            if(st.top() == '(' && !st.empty()){
                st.pop();
            }
            else{
                ans =false;
                break;
            }
        }
        else if(str[i]=='}'){
            if(st.top() == '{' && !st.empty()){
                st.pop();
            }
            else{
                ans =false;
                break;
            }
        }
        else if(str[i]==']'){
            if(st.top() == '[' && !st.empty()){
                st.pop();
            }
            else{
                ans =false;
                break;
            }
        }
    }
    return ans;
    
}

int main(){
    string str="((([{}])))";
    if(balancedParenthesis(str)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
}