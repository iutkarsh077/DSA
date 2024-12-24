#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[mid] > target)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int search2(vector<int> &nums, int target)
{

    if (nums.size() == 0)
        return -1;

    if (nums.size() == 1 && target != nums[0])
    {
        return -1;
    }

    if (nums.size() == 1 && target == nums[0])
    {
        return 0;
    }
     if (nums.size() == 1 && target == nums[0])
    {
        return 0;
    }
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
        {
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    return -1;
}

int main()
{
    return 0;
}