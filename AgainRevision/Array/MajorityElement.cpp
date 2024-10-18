#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 3, 3, 5, 8, 5, 5, 3, 5, 1};
    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    vector<int> ans;

    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        if (i->second > n / 3)
        {
            ans.push_back(i->first);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}