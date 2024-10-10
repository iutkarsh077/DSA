#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
}

int BetterApporach(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second > nums.size() / 2)
        {
            return i->first;
        }
    }

    return -1;
}

int OptimalApproach(vector<int> &nums)
{
    int element = nums[0];
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            element = nums[i];
            cnt++;
        }

        else if (element != nums[i])
        {
            cnt--;

        }

        else
        {
            cnt++;
        }
    }

    cout << "The majority elment is: " << element;
}

int main()
{
    vector<int> nums = {1};
    OptimalApproach(nums);
    return 0;
}