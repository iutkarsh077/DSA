#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 2 && nums[0] == nums[1]){
        nums.erase(nums.begin() + 1);
        return nums.size();
    }
int i = 1;
while(i < nums.size() - 1){
    if(nums[i] == nums[ i - 1] || nums[i] == nums[i + 1]){
        nums.erase(nums.begin() + i);
    }
    else{
         i = i + 1;
    }
}

 if(nums.size() == 2 && nums[0] == nums[1]){
        nums.erase(nums.begin() + 1);
    }
return nums.size();
}


int main() {
    return 0;
}