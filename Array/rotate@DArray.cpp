#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
     map<int, int> mpp;
     int nums[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
     int k = 3;
    int preSum = 0, cnt = 0;
    int n = sizeof(nums)/sizeof(nums[0]);
    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += nums[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return 0;

}