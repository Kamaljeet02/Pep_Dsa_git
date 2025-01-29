#include <iostream>
using namespace std;
void reverse(int arr[], int n){
    int s= 0;
    int e =n-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
int main() {
    // Write C++ code here
    int  n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    reverse(arr ,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "<<endl;
    }

    return 0;
}