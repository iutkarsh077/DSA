#include <bits/stdc++.h>
using namespace std;


void nlogn(int arr[]){
     int max = INT_MIN;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

}

int main() {
    int arr[] = {8, 1, 3, 2, 4, 9, 10282, 6, 8, 5, 4 ,5};
   
    return 0;
}