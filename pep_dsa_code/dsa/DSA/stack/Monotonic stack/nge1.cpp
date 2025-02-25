#include<iostream>
using namespace std;


// Next Greater element 1.
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> mp;
    vector<int> ans;
    stack<int> st;
    for(int i=nums2.size()-1 ; i>=0; i--){
        while(st.size()>0 && st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty()) mp[nums2[i]]=-1;
        else{
            mp[nums2[i]]=st.top();
            
        }
        st.push(nums2[i]);
    }
    for(int i=0; i<nums1.size(); i++){
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}

//Next greater element II ---circular array
vector<int> nextGreaterElements(vector<int>& nums) {
        
    stack<int> st;
    int n=nums.size();
    vector<int> ans(n);
    for(int i= 2*n-1; i>=0; i--){
        while(st.size()>0 && st.top()<=nums[i%n]){
            st.pop();
        }
        if(i<n){
            ans[i]= st.empty()? -1: st.top();
        }
        st.push(nums[i%n]);
    }
    return ans;
}

int man(){

}