#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }

        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}
void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + ((e - s) / 2);
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
int main()
{
    int arr[] = {4, 1, 2, 7, 6, 8, 92};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    int i = 0;
    while(i < n){
        cout << arr[i++] << " ";
    }
    return 0;
}

//Worst - best - Average Case Time complexity =  O(nlogn)