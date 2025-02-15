#include<iostream>
#include<cstring>
using namespace std;

string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans="";
        int n = s.size();
        for(int i =0; i<n; i++){
            string word ="";
            while(i<n &&s[i]!=' '){
                word +=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.length()>0) ans +=" "+word;
        }
        return ans.substr(1);
    }

 vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0, neg =1;
        int n= nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                ans[neg]=nums[i];
                neg +=2;
            }
            else{
                ans[pos]=nums[i];
                pos+=2;
            }
        }
        return ans;
}   

int main(){

}    