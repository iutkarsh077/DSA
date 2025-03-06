#include <iostream>
using namespace std;  

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int cnt = 0;
    
    
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < pivot)
            cnt++;
    }
    
    
    int pivotIndex = low + cnt;
    swap(arr[pivotIndex], arr[low]);
    
    int i = low, j = high;
    
  
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pivotIndex;
}

void QuickSort(int arr[], int low, int high) {
    if (low >= high) return;
    
    int p = partition(arr, low, high);
    
    
    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);
}

int main() {
    int arr[] = {4, 1, 2, 5, 3,  8, 564};
    int end = sizeof(arr) / sizeof(arr[0]);
    
    QuickSort(arr, 0, end - 1);
    
    for (int i = 0; i < end; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}