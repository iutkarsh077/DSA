#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e)
{
    vector<int> temp;
    int left = s;
    int right = mid + 1;

    while (left <= mid && right <= e)
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

    while (right <= e)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i - s];
    }
}

void mergeSort2(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + ((e - s) / 2);
    mergeSort2(arr, s, mid);
    mergeSort2(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};

    int i = 0;

    mergeSort2(arr, 0, arr.size() - 1);

    while (i < arr.size())
    {
        cout << arr[i] << " ";
        i++;
    }

    return 0;
}