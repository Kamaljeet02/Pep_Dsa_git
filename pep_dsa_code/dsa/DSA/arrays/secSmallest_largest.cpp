
#include <iostream>
#include<climits>
using namespace std;
int secondLargest(int arr[], int size){
    int max =arr[0];
    int secLast= -1;
    for(int i =0 ;i<=size-1 ;i++){
        if(arr[i]>max){
            secLast =max;
            max =arr[i];
        }
        else if(arr[i]<=max && arr[i]>secLast){
            secLast = arr[i];
        }
    }
    return secLast;
}
int secondSmallest(int arr[], int size){
    int min =arr[0];
    int secSmall= INT_MAX;
    for(int i =0 ;i<=size-1 ;i++){
        if(arr[i]<min){
            secSmall =min;
            min =arr[i];
        }
        else if(arr[i]>=min && arr[i]<secSmall){
            secSmall = arr[i];
        }
    }
    return secSmall;
}

int main() {
    int  size;
    cin>> size;
    
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    
    int g =secondLargest(arr ,size);
    int s=secondSmallest(arr ,size);
    cout<<"Second largest is "<<g<<" and second smallest is "<<s;


    return 0;
}