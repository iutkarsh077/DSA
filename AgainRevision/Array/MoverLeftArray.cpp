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

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    int i = 0;
    Rev(nums, k);
    while (i < nums.size())
    {
        cout << nums[i] << " ";
        i++;
    }
    return 0;
}