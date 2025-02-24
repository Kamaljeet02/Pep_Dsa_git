#include <iostream>
#include <stack>
#include<cmath>
using namespace std;

//polish notation. ...(prefix)
int postfixEval(string s){
    stack<int> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i] -'0'); //ascii val of 0 is sub. so that we get actual integer.
        }
        else{
            int operand2= st.top();
            st.pop();
            int operand1 =st.top();
            st.pop();

            switch(s[i]){
                case '+':
                st.push(operand1 + operand2);
                break;

                case '-':
                st.push(operand1 - operand2);
                break;

                case '*':
                st.push(operand1 * operand2);
                break;

                case '/':
                st.push(operand1 / operand2);
                break;

                case '^':
                st.push(pow(operand1 , operand2));
                break;
            }
        }
    }
    return st.top();
}

int prefixEval(string s){
    stack<int> st;

    for(int i=s.length()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i] -'0'); //ascii val of 0 is sub. so that we get actual integer.
        }
        else{
            int operand1= st.top();
            st.pop();
            int operand2 =st.top();
            st.pop();

            switch(s[i]){
                case '+':
                st.push(operand1 + operand2);
                break;

                case '-':
                st.push(operand1 - operand2);
                break;

                case '*':
                st.push(operand1 * operand2);
                break;

                case '/':
                st.push(operand1 / operand2);
                break;

                case '^':
                st.push(pow(operand1 , operand2));
                break;
            }
        }
    }
    return st.top();
}

//infix yo postfix
int priority(char c){
    if(c =='^') return 3;
    else if(c=='*'|| c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}

string infixToPostfix(string& s) {
    // Your code here
    stack<char> st;
    string ans ="";
    for(int i =0; i<s.size(); i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9')){
            ans +=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while( st.top()!='('){
                ans +=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&& priority(s[i])<=priority(st.top())){
                ans+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main() {
    

    string s="-+7*45+20";
    int pre =prefixEval(s);
    string p="562/-";
    cout<<"pre : "<<pre<<endl;
    int post =postfixEval(p);
    cout<<"post : "<<post<<endl;

    return 0;
}