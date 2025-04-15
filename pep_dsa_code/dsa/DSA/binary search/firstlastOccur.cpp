#include <iostream>

#include<map>
using namespace std;

// First and last Occurance of a number in an array
int firstOccur(vector<int>& nums, int target){
    int low=0;
    int high= nums.size()-1;
    int first =-1;
    while(low<=high){
        int mid =low +(high-low)/2;
        if(nums[mid]== target){
            first = mid;
            high =mid-1;
        }
        else if(nums[mid]<target){
            low =mid+1;
        }
        else high =mid-1;
    }
    return first;
}
int lastOccur(vector<int>& nums, int target){
    int low=0;
    int high= nums.size()-1;
    int last =-1;
    while(low<=high){
        int mid =low +(high-low)/2;
        if(nums[mid]== target){
            last = mid;
            low =mid+1;
        }
        else if(nums[mid]<target){
            low =mid+1;
        }
        else high =mid-1;
    }
    return last;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = firstOccur(nums ,target);
    if(first== -1) return {-1,-1};
    int last =lastOccur(nums, target);
    return {first, last};
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

// Search element in rotated sorted array ** duplicate elements
bool searchele(vector<int>& nums, int target) {
    int low =0;
    int high =nums.size()-1;
    while(low<=high){
        int mid=low+ (high-low)/2;
        if(nums[mid]==target) return true;
        if(nums[low]==nums[mid] && nums[mid]== nums[high]){
            low++;
            high--;
            continue;
        }
        //left sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<= nums[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(nums[mid]<=target && target<= nums[high]){
                low=mid+1;

            }
            else high= mid-1;
        }
    }
    return false;
}

//find minimum in rotated sorted array   Unique
int findMin(vector<int>& nums) {
    int low =0;
    int high =nums.size()-1;
    int mini= INT_MAX;
    while(low<=high){
        int mid= (low+high)/2;
        if(nums[low]<= nums[high]){
            mini =min(mini, nums[low]);
            break;
        }

        // LEFT SORTED
        if(nums[low]<=nums[mid]){
            mini =min(mini, nums[low]);
            //store minimum from sorted aprt and eliminate
            low= mid+1;
        }
        //Right sorted
        else{
            mini =min(mini, nums[mid]);
            high =mid-1;
        }

    }
    return mini;
}


// Find single non duplicate element
int singleNonDuplicate(vector<int>& nums) {
    int low =1;
    int high =nums.size()-2;
    if(nums.size()==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];

    while(low<=high){
        int mid =(low + high)/2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!= nums[mid-1]) return nums[mid];
        // We are on left halff
        //.   if mid is on odd position compare with previus odd.
        if((mid%2==1 && nums[mid-1] ==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low =mid+1; // eliminate left half 
        }
        else{
            high =mid-1;
        }
    }
    return -1;
}
int main() {
    
    
}