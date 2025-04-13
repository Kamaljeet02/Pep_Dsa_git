#include <iostream>

#include<map>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long, int> preSumMap;
        long long sum=0;
        int maxLen=0;
        for(int i=0; i<arr.size(); i++){
            sum +=arr[i];
            if(sum==k) {
                maxLen= max(maxLen, i+1);
            }
            long long rem= sum-k;
            if(preSumMap.find(rem)!=preSumMap.end()){
                int len= i-preSumMap[rem];
                maxLen= max(maxLen, len);
            }
            if(preSumMap.find(sum)==preSumMap.end()){
                preSumMap[sum]=i;
            }
        
        }
        return maxLen;
}

//Two Sum.
vector<int> twoSum(vector<int>& nums, int target) {
        map<int ,int> mpp;
        int req=0;
        for(int i=0; i<nums.size();i++){
            int num= nums[i];
            req= target -num;

            if(mpp.find(req)!=mpp.end()){
                return{mpp[req], i};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
}

//MAJORITY element in array..(>n/2)
int majorityElement(vector<int>& nums) {
        // Moore's voting algo..
        int cnt =0;
        int ele;
        for(int i=0; i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ele;
}

// Max score from sum array minimums.
int pairWithMaxSum(vector<int> &arr) {
        //  check the max sum of 2 conseq elements.
        int n =arr.size();
        int sum=0;
        int maxi =INT_MIN;
        for(int i =0;i<n-1;i++){
            sum =arr[i]+arr[i+1];
            if(sum>maxi) {
                maxi =sum;
            }
            
        }
        return maxi;
}

//Leaders in array
vector<int> leaders(vector<int>& arr) {
    // Code here
    vector<int> ans;
    int n= arr.size();
    int maxi= INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>=maxi){
            maxi=arr[i];
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// SEARCH IN SORTED ARRAY bs
int search(vector<int>& nums, int target) {
    int low =0;
    int high =nums.size()-1;
    while(low<=high){
        int mid =low +(high-low)/2;
        if(nums[mid]==target) return mid;
        //check which part is sorted
        //Left part sorted
        if(nums[low]<= nums[mid]){
            // check target exist between left side
            if(nums[low]<= target && target<= nums[mid]){
                high =mid-1;
            }
            //element is in right side
            else low= mid+1;
        }
        // RIGHT SORTED
        else{
            if(nums[mid]<= target && target <=nums[high]){
                low= mid+1;
            }
            else high= mid-1;
        }
    }
    return -1;
}
int main() {
    
    int  n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> arr1;
    longestSubarray(arr1 ,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "<<endl;
    }

    return 0;
}