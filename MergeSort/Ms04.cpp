#include <bits/stdc++.h>
using namespace std;
void print1(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int low, int mid, int high)
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

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    cout << "MergeSort 1" << endl;
    print1(arr);
    mergeSort(arr, mid + 1, e);
    cout << "MergeSort 2" << endl;
    print1(arr);
    merge(arr, s, mid, e);
}
int main()
{
    int arr[] = {6, 2, 1, 4};
    int n = 4;
    mergeSort(arr, 0, 3);
    cout << "Int main Function" << endl;
    print1(arr);
    return 0;
}
