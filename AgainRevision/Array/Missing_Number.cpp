#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    if (nums.size() == 1 && nums[0] == 1)
    {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
    }

    int n = nums.size();
    int total = (n * (n + 1)) / 2;
    int result = total - sum;
    return result;
}

int OptimalAppraoch(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    if (nums[0] == 1)
    {
        return 0;
    }

    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (mid - 1 >= 0 && nums[mid - 1] == mid - 1 && nums[mid] == mid + 1)
        {
            return mid;
        }
        else if (nums[mid] == mid)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0};
    int val = OptimalAppraoch(arr);
    cout <<  val;
    return 0;
}