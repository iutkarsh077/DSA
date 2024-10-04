#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void MergeSort(int arr[], int low, int mid, int high)
{
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

void DivideArray(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + ((high - low) / 2);
    DivideArray(arr, low, mid);
    DivideArray(arr, mid + 1, high);
    MergeSort(arr, low, mid, high);
}
int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;
    DivideArray(arr, low, high);

    for (int i = 0; i < high + 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}