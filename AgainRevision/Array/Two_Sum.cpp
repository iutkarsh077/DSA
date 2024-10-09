#include <bits/stdc++.h>
using namespace std;

void BetterApproach(vector<int> nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];

        if (mp.find(rem) != mp.end())
        {

            cout << mp[rem] << " " << i << endl;
            return;
        }

        mp[nums[i]] = i;
    }
}

int main()
{
    vector<int> nums = {3, 3};
    int target = 6;
    int left = 0;
    int right = nums.size() - 1;
    //Another approach is Two Pointer approach it is not optimal but anothe rappraoch to solve the same question
    return 0;
}
