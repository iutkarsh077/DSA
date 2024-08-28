#include <bits/stdc++.h>
using namespace std;

int LeftMax(int i, vector<int> nums)
{
    int maxVal = nums[i];
    for (int j = i; j >= 0; j--)
    {
        maxVal = max(maxVal, nums[j]);
    }
    return maxVal;
}

int RightMax(int i, vector<int> nums)
{
    int maxVal = nums[i];
    for (int j = i + 1; j < nums.size(); j++)
    {
        maxVal = max(maxVal, nums[j]);
    }
    return maxVal;
}

int main()
{
    vector<int> nums = {4, 2, 0, 3, 2, 5};
    vector<int> prefixMax(nums.size());
    vector<int> suffixMax(nums.size());

    // Fill prefixMax
    prefixMax[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        prefixMax[i] = max(nums[i], prefixMax[i - 1]);
    }

    // Fill suffixMax
    suffixMax[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--) {
        suffixMax[i] = max(nums[i], suffixMax[i + 1]);
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int max_left = prefixMax[i];
        int max_right = suffixMax[i];
        int mini = min(max_left, max_right) - nums[i];
        sum += mini;
    }

    cout << sum << endl;
    return 0;
}