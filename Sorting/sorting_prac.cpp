#include <bits/stdc++.h>
using namespace std;

// Bubble Sort
/*int main() {
    int arr[] = {4, 1, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    int i = 0;
    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}*/

// Selection Sort
/*int main(){
    int arr[] = {4, 1, 2, 5, 3, 2 ,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n - 1; i++){
        int big_val = i;
        for(int j = i + 1; j < n; j++){
            if(arr[big_val] > arr[j]){
                big_val = j;
            }
        }
        swap(arr[big_val], arr[i]);
    }
    int i = 0;
    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}
*/

// Insertion Sort
/*int main()
{
    int arr[] = {4, 1, 2, 5, 3, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1, j, temp; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }

            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }

     for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}*/

// Merge Sort
/*void merge(int arr[], int low, int mid, int high)
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

    for (int i = low; i <= high; i++)
    {
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
    int arr[] = {4, 1, 2, 5, 3, 2, 8, 564, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    mergeSort(arr, low, high);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}*/

// Quick Sort

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int cnt = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = cnt + low;
    swap(arr[low], arr[pivotIndex]);

    int i = low;
    int j = high;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
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
    int arr[] = {4, 1, 2, 5, 3, 2, 8, 564, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    quickSort(arr, low, high);

    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}