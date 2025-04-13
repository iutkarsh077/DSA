#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int largestElement(vector<int> &nums)
{
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }

    return maxi;
}

int findKthLargestBrute(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int findKthLargest(vector<int> &nums, int k)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    int cnt = 0;
    for (auto i = mp.rbegin(); i != mp.rend(); i++)
    {
        cnt = cnt + i->second;
        if (cnt >= k)
            return i->first;
    }

    return -1;
}

int main()
{
    map<int, int> mp;
    vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    return 0;
}