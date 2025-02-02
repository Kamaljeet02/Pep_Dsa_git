#include <iostream>
using namespace std;

//Find n.o that appear once and other number twice...

int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for(int i=0; i<nums.size();i++){
        xorr = xorr ^ nums[i];
   }
    return xorr;
}


int main() {

    
    

    return 0;
}