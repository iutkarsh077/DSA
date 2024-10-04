#include <bits/stdc++.h>
using namespace std;


/*void hdkdds(int arr[]){
     int max = INT_MIN;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

}*/

int main() {
    int arr[] = {8, 1, 3, 2, 4, 9, 10282, 6, 8, 5, 4 ,5};
     int max = INT_MIN;
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);
    cout << arr[n - 2];
    return 0;
}