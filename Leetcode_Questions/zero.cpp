#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void moveZeroes(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1){
        return;
    }


    int cntZero = 0;
    int i = 0;

   while(i < nums.size()){
        if(nums[i] == 0){
            cntZero++;
            nums.erase(nums.begin() + i);
        }
        else{
            i++;
        }
    }

    for(int i = 0; i < cntZero; i++){
        nums.push_back(0);
    }

    return;
}

int main() {
    return 0;
}