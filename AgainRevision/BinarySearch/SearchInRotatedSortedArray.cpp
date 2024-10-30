#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    if (nums.size() == 0)
        return -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[s] <= nums[mid])
        {
            if (nums[mid] >= target && nums[s] <= target)
            {
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }
        }

        if (nums[mid] < nums[e])
        {
            if (nums[mid] <= target && nums[e] >= target)
            {
                s = mid + 1;
            }

            else
            {
                e = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> temp = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    return 0;
}