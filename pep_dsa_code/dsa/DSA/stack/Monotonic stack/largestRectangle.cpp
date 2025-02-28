#include<iostream>
using namespace std;

//Largest rectangle in histogram....hard
int largestRectangleArea(vector<int>& heights) {
    int maxArea =0;
    stack<int> st;
    int n= heights.size();
    int nse,pse, element;
    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            element = st.top();
            st.pop();
            nse =i;
            pse =st.empty()? -1:st.top();
            maxArea =max(maxArea, (heights[element]* (nse -pse -1)));
        }
        st.push(i);
    }
    while(!st.empty()){
        nse =n;
        element =st.top();
        st.pop();
        pse =st.empty()?-1: st.top();
        maxArea =max(maxArea, (heights[element]* (nse -pse -1)));
    }
    return maxArea;
}

int main(){

}