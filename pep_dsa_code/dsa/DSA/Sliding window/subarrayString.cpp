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

int main(){

}