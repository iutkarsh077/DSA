#include <bits/stdc++.h>
using namespace std;

void printMe(int arr[], int s, int e){
    for(int i = 0; i <= e; i++){
        cout << arr[i] << " ";
    }
}

int partition(int arr[], int s, int e){
    int cnt = 0;
    int pivot = arr[s];

    for(int i = s + 1; i <= e; i++){
        if(pivot >= arr[i]){
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);


    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    cout << "zero ";
    printMe(arr, s ,e);
    cout << endl;
    int p = partition(arr, s, e);
    cout << "first ";
    printMe(arr, s ,p);
    cout << endl;
    quickSort(arr, s, p - 1);
    cout << "second ";
    printMe(arr, p + 1 ,e);
    cout << endl;
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {5, 3, 1, 2};
    int s = 0;
    int e = 3;
    quickSort(arr, s, e);
    int i = 0;
    while(i <  4){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}