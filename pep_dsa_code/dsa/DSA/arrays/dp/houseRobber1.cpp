#include<iostream>
using namespace std;

int rob(vector<int>& nums) {
    int l =nums.size();
    if(l==0) return 0;
    if(l==1) return nums[0];
    if(l==2) return max(nums[0],nums[1]);

    vector<int> track(l,0);
    track[0]= nums[0];
    track[1]= max(nums[0],nums[1]);
    track[2] =max(nums[1], nums[2]+track[0]);

    for(int i=2; i<l ;i++){
        track[i]= max(track[i-1], nums[i]+ track[i-2]);
    }
    return max(track[l-1], track[l-2]);
}
int main(){

}