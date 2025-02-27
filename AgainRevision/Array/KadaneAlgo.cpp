#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        maxi = max(sum, maxi);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int maxSubArray2(vector<int> &nums)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        maxi = max(sum, maxi);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    return 0;
}