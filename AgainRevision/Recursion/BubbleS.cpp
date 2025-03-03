#include<iostream>
using namespace std;

void SortThis(int arr[], int n){
    if(n == 0 || n == 1) return;

    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i  + 1]) swap(arr[i], arr[i + 1]);
    }

    SortThis(arr, n - 1);
}

int main(){
    int arr[] = {4, 2, 6, 5 ,1};
    SortThis(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << " ";
    }

}