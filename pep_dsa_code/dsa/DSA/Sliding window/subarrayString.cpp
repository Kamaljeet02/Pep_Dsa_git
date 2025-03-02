#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

//longest subarray without repeating char.
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int pointer=0;
    int maxl=0;
    for(int i=0; i<s.length();i++){
        char c =s[i];
        if(mp.count(c)>0){
            pointer =max(pointer, mp[c]+1);
        }
        mp[c]=i;
        maxl= max(maxl, i-pointer +1);
    }
    return maxl;
}

// Sliding window maximum...hard
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;
    for(int i=0; i<nums.size(); i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){

}