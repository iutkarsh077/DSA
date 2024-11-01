#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        return nums[nums.size() - 1];
    }
    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }

    return -1;
};

int main()
{
    vector<int> nums = {1};
    int val = -1;
    if (nums.size() == 1)
    {
        cout << nums[0];
        return nums[0];
    }

    if (nums[0] != nums[1])
    {
        cout << nums[0];

        return nums[0];
    }

    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        cout << nums[nums.size() - 1];
        return nums[nums.size() - 1];
    }

    int s = 0;
    int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + ((e - s) / 2);

            if (mid > 0 && (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]))
            {
                val = nums[mid];
                break;
            }

            else if ((nums[mid] == nums[mid - 1] && mid % 2 != 0) || (nums[mid] == nums[mid + 1] && mid % 2 == 0))
            {
                s = mid + 1;
            }

            else if ((nums[mid] == nums[mid - 1] && mid % 2 == 0) || (nums[mid] == nums[mid + 1] && mid % 2 != 0))
            {
                e = mid - 1;
            }
        }

    cout << val;
    return 0;
}