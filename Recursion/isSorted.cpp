#include <bits/stdc++.h>
using namespace std;

bool IsSorted(int arr[], int n, int start){
    if(start >= n - 1){
        return true;
    }

    if(arr[start] > arr[start + 1]){
        return false;
    }

    return IsSorted(arr, n, start + 1);
}

int main() {
    int arr[] = {2, 4, 6, 9, 11, 132};
    int n = sizeof(arr)/sizeof(arr[0]); 
    bool val = IsSorted(arr, n, 0);
    cout << val;
    return 0;
}