#include<iostream>
#include<vector>
using namespace std;

void BubbleMe(vector<int> &arr, int i){
    if(i == arr.size() - 1) return;

    for(int j = 0; j < arr.size() - i - 1; j++){
        if(arr[j] > arr[j + 1]){
            swap(arr[j], arr[j + 1]);
        }
    }

    i = i + 1;
    BubbleMe(arr, i);
} 

void InsertMe(vector<int> &arr, int i){
    if(i == arr.size()) return;

    int temp = arr[i];
    int j;
    for(j = i - 1; j >= 0; j--){
        if(arr[j] >temp){
            arr[j + 1] = arr[j];
        }
        else{
            break;
        }
    }

    arr[j + 1] = temp;
    i = i + 1;
    InsertMe(arr, i);
}

int Partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int cnt = 0;

    for(int i = low + 1; i <= high; i++){
        if(arr[i] <= pivot) cnt++;
    }

    int pivotIndex = cnt + low;
    swap(arr[pivotIndex], arr[low]);

    int i = low;
    int j = high;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot) i++;

        while(arr[j] > pivot) j--;

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
};

void QuickSort(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int p = Partition(arr, low, high);
    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);
} 

int main(){
    vector<int> arr= {5, 1, 7, 9, 4, 8, 3, 90, 2};
    QuickSort(arr, 0, arr.size() - 1);
    int i = 0;
    while(i < arr.size()){
        cout << arr[i] << " ";
        i = i + 1;
    }

    return 0;
}