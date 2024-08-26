#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 4, 5, 7, 8, 9, 10, 12, 14, 15, 17, 19, 20, 22, 24, 25, 27, 28, 29, 30};

    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    int target = 30;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            cout << "The " << target << " is found at index " << mid << endl;
            return 0;
        }

        else if(arr[mid] > target){
            end = mid - 1;
        }

        else{
            start = mid + 1;
        }
    }
    cout << "Element is not Present in the array\n";
    return 0;
}