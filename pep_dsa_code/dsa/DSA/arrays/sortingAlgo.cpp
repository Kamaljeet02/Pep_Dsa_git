
#include <iostream>
// #include<bits/stdc++.h>
using namespace std;
void selectionsort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int min =i;
        for(int j=i; j<n; j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[min],a[i]);
    }
}
void bubblesort(int a[], int n){
    for(int i=n-1; i>=1;i--){
        bool isswap=false;
        for(int j=0; j<=i-1; j++){
            if(a[j+1]<a[j]){
                swap(a[j], a[j+1]);
                isswap=true;
            }
        }
        if(isswap==false) break;
    }
}

// Merge Sort
void merge(vector<int> &arr ,int l ,int mid , int r ){
    vector<int> temp;
    int left = l;
    int right =mid+1;
    while(left<=mid && right <=r){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=r){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i=l; i<=r; i++){
        arr[i]=temp[i-l];
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    // code here
    if(l>=r) return;
    int mid =(l+r)/2;
    mergeSort(arr ,l , mid);
    mergeSort(arr ,mid+1 ,r);
    merge(arr , l , mid , r);
}
int main() {
 
    int n;
    cin>> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>> a[i];
    }
    // selectionsort(a, n);
    bubblesort(a ,n);
    
    for(int i =0;i<n;i++){
        cout<< a[i]<<" ";
    }
    
    

    return 0;
}