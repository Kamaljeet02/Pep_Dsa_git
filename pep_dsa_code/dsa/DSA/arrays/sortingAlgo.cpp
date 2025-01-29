
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