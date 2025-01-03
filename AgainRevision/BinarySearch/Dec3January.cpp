#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class OptimizedSolution
{
    long long int calc(vector<int> nums, int val)
    {
        long long int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += ceil((double)nums[i] / val);
        }

        return totalSum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }

        int ans = -1;

        int s = 1;
        int e = maxi;

        while (s <= e)
        {
            int mid = s + ((e - s) / 2);
            int result = calc(nums, mid);

            if (result <= threshold)
            {
                ans = mid;
                e = mid - 1;
            }

            else if (result > threshold)
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};

long long int calc(vector<int> nums, int val)
{
    long long int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalSum += ceil((double)nums[i] / val);
    }
    cout << totalSum;

    return totalSum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }

    int ans = -1;

    for (int i = 1; i <= maxi; i++)
    {
        int result = calc(nums, 5);
        if (result <= threshold)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    smallestDivisor(nums, 6);
    return 0;
}
