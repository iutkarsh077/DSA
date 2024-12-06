#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

  vector<int> leaders(vector<int>& nums) {
        // Code here
         int maxi = INT_MIN;
            vector<int> result;
            
            for(int i = nums.size() - 1; i >= 0; i--){
                if(nums[i] >= maxi){
                    result.push_back(nums[i]);
                    maxi = nums[i];
                }
            }
            
            reverse(result.begin(), result.end());
            return result;
    }
int main() {
    vector<int> nums = {61, 61, 17};
    vector<int> ans = leaders(nums);
    return 0;
}