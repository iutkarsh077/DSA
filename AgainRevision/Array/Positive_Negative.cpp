#include <bits/stdc++.h>
using namespace std;

vector<int> Optimal(vector<int> &nums)
{
    vector<int> ans(nums.size());

    int val = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            ans[val] = nums[i];
            val = val + 2;
        }
    }

    val = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            ans[val] = nums[i];
            val = val + 2;
        }
    }

    return ans;
}

vector<int> Optimal(vector<int> &nums)
{
    vector<int> ans(nums.size());

    int p = 0;
    int n = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            ans[p] = nums[i];
            p += 2;
        }

        else
        {
            ans[n] = nums[i];
            n += 2;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    return 0;
}