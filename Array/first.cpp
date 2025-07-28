#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumBrute(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }

    return {-1, -1};
}

vector<int> twoSumBetter(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];
        if (mp.find(need) != mp.end())
        {
            return {i, mp[need]};
        }
        mp.insert({nums[i], i});
    }
    return {-1, -1};
}

vector<int> mySumRecursive(vector<int> &nums, int target, unordered_map<int, int> &mp, int i)
{
    if (i == nums.size())
        return {};

    int need = target - nums[i];
    if (mp.find(need) != mp.end())
    {
        return {i, mp[need]};
    }

    mp[nums[i]] = i;
    i = i + 1;
    return mySumRecursive(nums, target, mp, i);
}

int slideWindow(vector<int> nums, int k)
{
    int l = 0;
    int r = k - 1;
    int maxi = 0;

    while (r < nums.size())
    {
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum = sum + nums[i];
        }

        maxi = max(sum, maxi);
        l++;
        r++;
    }

    cout << "Max Value is: " << maxi << endl;
}

void DS()
{
    vector<int> nums = {2, 5, 1, 10, 10};
    int k = 14;
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxi = 0;

    while (r < nums.size())
    {
        sum = sum + nums[r];

        while (sum > k)
        {
            sum = sum - nums[l];
            l = l + 1;
        }

        if (sum <= k)
        {
            maxi = max(maxi, sum);
            r++;
        }
    }

    cout << "Max consecutive sum is: " << maxi;
}
int main()
{
    // vector<int> nums = {2, -1, 3, 3, 8, -1, -4};
    // slideWindow(nums, 4);
    DS();
    return 0;
}