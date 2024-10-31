#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int mini = INT_MAX;
    vector<int> nums = {18, 11,13,15,17};

    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[s] <= nums[mid])
        {
            mini = min(nums[s], mini);
            s = mid + 1;
        }

        else if (nums[mid] <= nums[e])
        {
            mini = min(nums[mid], mini);
            e = mid - 1;
        }
    }

    cout << mini;
    return 0;
}