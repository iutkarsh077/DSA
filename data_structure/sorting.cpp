#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// void selectionSort(int arr[], int size){
//     for(int i = 0; i < size - 1; i++){
//         int minIndex = i;
//         for(int j = i + 1; j < size; j++){
//             if(arr[minIndex] < arr[j]){
//                 minIndex = j;
//             }
//         }
//         swap(arr[minIndex], arr[i]);
//     }
// }

// void bubbleSort(int arr[], int size){
//     for(int i = 0; i < size - 1; i++){
//         bool swapped = false;
//         for(int j = 0; j < size - i; j++){
//             if(arr[j] > arr[j + 1]){
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }

//         if(swapped == false) break;
//     }
// }

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int val = arr[i];
        for (; j >= 0; j--)
        {
            if (val < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = val;
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

void divide(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + ((high - low) / 2);

    divide(arr, low, mid);
    divide(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[7] = {5, 4, 8, 2, 1, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}