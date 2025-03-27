#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int resultedIndex = -1;
    int s = 0;
    int e = nums.size() - 1;

    while(s <= e){
        int mid = s + ((e - s)/2);

        if(nums[mid] == target) return mid;

        else if(nums[mid] < target){
            s = mid + 1;
            resultedIndex = mid + 1;
        }

        else{
            e = mid - 1;
            resultedIndex = mid;
        }
    }

    return resultedIndex;
}

int main() {
    return 0;
}