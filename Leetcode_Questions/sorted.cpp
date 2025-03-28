#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int resultedIndex = -1;
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
            resultedIndex = mid + 1;
        }

        else
        {
            e = mid - 1;
            resultedIndex = mid;
        }
    }

    return resultedIndex;
}

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    digits[n - 1] += 1;
    for (int i = n - 1; i > 0 && digits[i] == 10; i--)
    {
        digits[i] = 0;
        digits[i - 1] += 1;
    }

    if (digits[0] == 10)
    {
        digits[0] = 1;
        digits.push_back(0);
    }

    return digits;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0)
    {
        nums1 = nums2;
        return;
    }
    if (n == 0)
        return;

    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }

        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }

    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }

    nums1 = ans;
    return;
}

int main()
{
    return 0;
}