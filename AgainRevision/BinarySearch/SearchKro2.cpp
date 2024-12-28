#include <bits/stdc++.h>
using namespace std;

bool searchBrute(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return true;
        }
    }
    return false;
}

int findKRotationBrute(vector<int> &arr)
{
    // Code Here
    int minIndex = 0;
    int minVal = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

bool search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return true;
        }

        if (nums[s] == nums[mid] && nums[mid] == nums[e])
        {
            s++;
            e--;
            continue;
        }

        if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && nums[mid] >= target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        if (nums[mid] <= nums[e])
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

    return false;
}

int main()
{
    return 0;
}