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

int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        return nums[nums.size() - 1];
    }

    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (mid > 0 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if ((nums[mid] == nums[mid + 1] && mid % 2 == 0) || (nums[mid] == nums[mid - 1] && mid % 2 != 0))
        {
            s = mid + 1;
        }

        if ((nums[mid] == nums[mid - 1] && mid % 2 == 0) || (nums[mid] == nums[mid + 1] && mid % 2 != 0))
        {
            e = mid - 1;
        }
    }

    return -1;
}

int findPeakElementBrute(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }

    if (nums[0] > nums[1])
    {
        return 0;
    }

    if (nums[nums.size() - 1] > nums[nums.size() - 2])
    {
        return nums.size() - 1;
    }

    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            return i;
        }
    }

    return -1;
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

int floorSqrtBrute(int n)
{
    // Your code goes here
    int mini = 1;
    for (int i = 0; i <= n / 2; i++)
    {
        if (i * i == n)
        {
            return i;
        }
        if (i * i < n)
        {
            mini = i;
        }
    }

    return mini;
}

int floorSqrt(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int s = 1;
    int e = n;
    int result = 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if(mid * mid == n){
            return mid;
        }

        else if(mid * mid > n){
            e = mid - 1;
        }
        else if(mid * mid < n){
            s = mid + 1;
            result = mid;
        }
    }

    return result;
}

int main()
{
    int result = floorSqrt(0);
    cout << result;
    return 0;
}