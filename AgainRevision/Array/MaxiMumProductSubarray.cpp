#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> nums = {0, 2};
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }

        if (suffix == 0)
        {
            suffix = 1;
        }

        prefix *= nums[i];
        suffix *= nums[nums.size() - i - 1];

        maxi = max(maxi, max(prefix, suffix));
    }

    cout << maxi;
}