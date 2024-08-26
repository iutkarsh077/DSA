#include <bits/stdc++.h>
using namespace std;

/*void merge(int arr[], int low, int mid, int high)
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
}*/

/*void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + ((high - low) / 2);

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}*/

/*void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxVal = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[maxVal] > arr[j])
            {
                maxVal = j;
            }
        }
        swap(arr[i], arr[maxVal]);
    }
}*/

/*void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}*/

/*void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        for (; j >= 0; j--)
        {
            if(arr[j] > temp){
                arr[j + 1] = arr[j];
            }

            else{
                break;
            }
        }
        arr[j + 1] = temp;
    }
}*/

int main()
{
    int arr[] = {4, 1, 2, 5, 7, 2, 8, 9, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}