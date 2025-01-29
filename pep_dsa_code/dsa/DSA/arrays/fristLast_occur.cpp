// last occur
// #include <iostream>
// using namespace std;
// int lastOccur(int arr[] ,int n , int key){
//     int start =0;
//     int end = n-1;;
//     int mid =(start +end)/2;
//     int ans =-1;
//     while(start<=end){
//         int mid =(start +end)/2;
//         if(arr[mid]==key){
//             ans= mid;
//             start= mid+1;
//         }
//         else if(arr[mid]<key){
//             start = mid+1;
            
//         }
//         else{
//             end =mid-1;
//         }
        
//     }
//     return ans;
// }
// int main() {
//     int  n;
//     cin>> n;
//     int key;
    
//     cin >>key;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
    
//     int f =lastOccur(arr ,n, key);
//     cout<<" last key found at "<<f<<" index";


//     return 0;
// }

//first occur

#include <iostream>
using namespace std;
int firstOccur(int arr[] ,int n , int key){
    int start =0;
    int end = n-1;;
    int mid =(start +end)/2;
    int ans =-1;
    while(start<=end){
        int mid =(start +end)/2;
        if(arr[mid]==key){
            ans= mid;
            end= mid-1;
        }
        else if(arr[mid]<key){
            start = mid+1;
            
        }
        else{
            end =mid-1;
        }
        
    }
    return ans;
}
int main() {
    int  n;
    cin>> n;
    int key;
    
    cin >>key;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int f =firstOccur(arr ,n, key);
    cout<<"key found at "<<f<<" index";


    return 0;
}