#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void Brute(vector<int> nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > 2 * nums[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}

int cnt = 0;

void merge(vector<int> &arr, int low, int mid, int high)
{
    // Count reverse pairs for elements that cross the two halves
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && static_cast<long long>(arr[i]) > 2 * static_cast<long long>(arr[j]))
        {
            j++;
        }
        cnt += (j - (mid + 1));
    }

    // Proceed with the standard merge operation
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + ((high - low) / 2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> nums = {2, 4, 3, 5, 1};
    // Brute(nums);

    mergeSort(nums, 0, nums.size() - 1);

    cout << cnt;
    return 0;
}
