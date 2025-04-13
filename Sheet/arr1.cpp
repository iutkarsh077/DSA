#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int largestElement(vector<int>& nums) {
    int maxi = INT_MIN;

    for(int i = 0; i < nums.size(); i++){
        maxi = max(maxi, nums[i]);
    }

    return maxi;
}

int findKthLargest(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main() {
    return 0;
}