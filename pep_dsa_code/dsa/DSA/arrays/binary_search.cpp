
#include <iostream>
using namespace std;
int binaryS(int arr[], int n, int key){
    int start= 0;
    int end= n-1;
    int mid =(start +end)/2;
    while(start<=end){
        if(arr[mid]==key) return mid;
        else if(arr[mid] >key){
            end =mid-1;
            
        }
        else{
            start=mid+1;
        }
        mid= (start +end)/2;
    }
    return -1;
}

int findFloor(vector<int>& arr, int k) {
        // Your code here
        int n =arr.size();
        int low =0;
        int high = n-1;
        int ans =-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(arr[mid] <=k){
                ans =mid;
                low =mid+1;
            }
            else{
                high =mid-1;
            }
            
        }
        return ans;
}
int main() {
   
    int  n;
    cin>> n;
    int key;
    cout<<"enter key "<<endl;
    cin >>key;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans=binaryS(arr ,n, key);
    cout<<"key found at "<<ans<<" index";

    return 0;
}