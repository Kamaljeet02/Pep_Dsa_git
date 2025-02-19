#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size =0;
    }

    void insert(int val){
        size =size+1;
        int index =size;
        arr[index]= val;

        while(index >1){
            int parent =index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size==0){
            return;
        }
        // replace first node with last
        arr[1]=arr[size];
        // remove last element
        size--;

        //take root at its correct pos
        int i =1;
        while(i<size){
            int leftIdx= 2*i;
            int rightIdx =2*i+1;

            if(leftIdx<size && arr[i]<arr[leftIdx]){
                swap(arr[i],arr[leftIdx]);
                i=leftIdx;
            }
            else if(rightIdx <size && arr[i]<arr[rightIdx]){
                swap(arr[i],arr[rightIdx]);
                i=rightIdx;
            }
            else{
                return;
            }
            
        }
    }

};

//Heapify
void heapify(int arr[], int n, int i){
    int largest =i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<n && arr[largest] < arr[left]){
        largest =left;
    }
    if(right<n && arr[largest] < arr[right]){
        largest =right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){

    heap h;
    h.insert(20);
    h.insert(15);
    h.insert(18);
    h.insert(22);


    h.print();

    int arr[6]= {-1,24,23,25,22,20};
    int n= 5;
    for(int i=n/2; i>0;i--){
        heapify(arr,n,i);

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    

}