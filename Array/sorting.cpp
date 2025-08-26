#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort()
{
    vector<int> nums;
    nums = {-4, -1, -2, -6, -74, -6, -1, -87, -56, -43};

    for (int i = 0; i < nums.size(); i++)
    {
        int mini = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[mini] > nums[j])
            {
                mini = j;
            }
        }
        swap(nums[mini], nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void bubbleSort()
{
    vector<int> nums;
    nums = {-4, -1, -2, -6, -74, -6, -1, -87, -56, -43};

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void insertionSort()
{
    vector<int> nums;
    nums = {4, 1, 2, -6, -74, -6, -1, -87, -56, -43};

    for (int i = 0; i < nums.size(); i++)
    {
        int j = i - 1;
        int temp = nums[i];
        for (; j >= 0; j--)
        {
            if (nums[j] > temp)
            {
                nums[j + 1] = nums[j];
            }
            else
            {
                break;
            }
        }
        nums[j + 1] = temp;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void merge(vector<int> &nums, int low, int high, int mid)
{
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left = left + 1;
        }
        else
        {
            temp.push_back(nums[right]);
            right = right + 1;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left = left + 1;
    }

    while (right <= high)
    {
        temp.push_back(nums[right]);
        right = right + 1;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

void divide(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + ((high - low) / 2);
    divide(nums, low, mid);
    divide(nums, mid + 1, high);
    merge(nums, low, high, mid);
}

int partition(vector<int> &nums, int s, int e)
{
    int pivot = nums[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (nums[i] <= pivot)
            cnt++;
    }

    int pivotIndex = cnt + s;
    swap(nums[s], nums[pivotIndex]);
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (nums[i] <= pivot)
        {
            i++;
        }

        while (nums[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(nums[i], nums[j]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(nums, s, e);
    quickSort(nums, s, p - 1);
    quickSort(nums, p + 1, e);
}

int main()
{
    vector<int> nums = {4, 1, 2, 7, 4, 3, 9, 8, 6, 5, 6, 3};
    int s = 0;
    int e = nums.size() - 1;
    quickSort(nums, s, e);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}