#include<iostream>
using namespace std;

// trapping water ..hard
int trap(vector<int>& height) {
    int lmax=0;
    int rmax=0;
    int total =0;
    int l=0;
    int r=height.size()-1;
    while(l<r){
        if(height[l]<= height[r]){
            if(lmax >height[l]){
                total +=lmax -height[l];
            }
            else{
                lmax =height[l];
            }
            l++;
        }
        else{
            if(rmax > height[r]){
                total += rmax -height[r];
            }
            else{
                rmax =height[r];
            }
            r--;
        }
    }
    return total;

}

int man(){

}