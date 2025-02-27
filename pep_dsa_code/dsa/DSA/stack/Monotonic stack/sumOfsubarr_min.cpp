#include<iostream>
using namespace std;

vector<int>findNSE(vector<int> arr){
    int s= arr.size();
    vector<int> n(s);
    stack<int> s1;
    for(int i=s-1; i>=0; i--){
        while(!s1.empty() && arr[s1.top()]>=arr[i]){
            s1.pop();
        }
        n[i]= s1.empty()?s :s1.top();
        s1.push(i);
    }
    return n;
}

vector<int> findPSEE(vector<int> arr){
    int x =arr.size(); 
    vector<int> p(x);
    stack<int> s2;
    for(int i=0; i<x; i++){
        while(!s2.empty() && arr[s2.top()]>arr[i]){
            s2.pop();
        }
        p[i] = s2.empty()?-1: s2.top();
        s2.push(i);
    }
    return p;
}

int sumSubarrayMins(vector<int>& arr) {
    int sum =0;
    vector<int> nse =findNSE(arr);
    vector<int>psee= findPSEE(arr);
    int n= arr.size();
    int mod = (int) (1e9+7);
    for(int i=0; i<n; i++){
        int left = i-psee[i];  //n.o of ele in left of n.o
        int right =nse[i] -i;
        sum =(sum +(left* right *1LL* arr[i]) %mod) %mod;

    }
    return sum;
}

int main(){
    
}