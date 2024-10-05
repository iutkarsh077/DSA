#include <bits/stdc++.h>
using namespace std;

void Rev(vector<int> &nums, int k)
{
    int idx = nums.size() - (k % nums.size());
    vector<int> arr;

    for (int i = idx; i < nums.size(); i++)
    {
        arr.push_back(nums[i]);
    }

    for (int i = 0; i < idx; i++)
    {
        arr.push_back(nums[i]);
    }

    nums.clear();

    for (int i = 0; i < arr.size(); i++)
    {
        nums.push_back(arr[i]);
    }
}

void RevByLoop(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        int temp = nums[0];
        for (int j = 0; j < n - 1; j++)
        {
            nums[j] = nums[j + 1];
        }
        nums[n - 1] = temp;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    int i = 0;
    RevByLoop(nums, k);
    while (i < nums.size())
    {
        cout << nums[i] << " ";
        i++;
    }
    return 0;
}