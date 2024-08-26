#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }

        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
            left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
            right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {1, 5, 2, 8, 4, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    mergeSort(arr, low, high);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}