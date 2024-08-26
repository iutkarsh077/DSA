#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int cnt = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (pivot >= arr[i])
        {
            cnt++;
        }
    }

    int pivotIndex = cnt + low;
    swap(arr[pivotIndex], arr[low]);

    int i = low;
    int j = high;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <=  pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }   

    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main()
{
    int arr[] = {6, 4, 12, 9, 0, 5, 3, 0, 8, 44, 4, 4, 1, 2, 3, 6, 3, 8, 6, 9 , 6, 5, 444, 3, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    int i = 0;

    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}