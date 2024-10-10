#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void BuySellBrute(vector<int> nums)
{
    int maxiProfit = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int mini = INT_MAX;
        int idxMini = -1;
        for (int j = i; j < nums.size(); j++)
        {
            if (mini > nums[j])
            {
                mini = nums[j];
                idxMini = j;
            }
        }


        int maxi = INT_MIN;
        for (int k = nums.size() - 1; k > idxMini; k--)
        {
            if (maxi < nums[k])
            {
                maxi = nums[k];
            }
        }

    // cout << maxi << endl;
        if (maxi != INT_MIN)
        {
            maxiProfit = max(maxiProfit, maxi - mini);
        }
    }

    cout << "The value is: " << maxiProfit;
    return;
}

int main()
{
    vector<int> nums = {7,1,5,3,6,4};
    BuySellBrute(nums);
    return 0;
}