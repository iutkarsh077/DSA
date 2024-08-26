#include <bits/stdc++.h>
using namespace std;

/*int main() {

    int arr[] = {3, 8, 10, 17, 1};

    int s = 0;
    int e = 4;
    int val = -1;
    while(s <= e){
        int mid = s + (e - s)/2;

        if(arr[mid] > arr[mid + 1]){
            val = mid + 1;
            break;
        }

        else if(arr[mid] < arr[0] && arr[mid] < arr[4]){
            e = mid - 1;
        }

        else{
            s = mid + 1;
        }
    }
    cout << val;
    return 0;
}*/

int main()
{
    int arr[] = {7, 0, 1, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e  = n - 1;
    int pivot = -1;

    while(s <= e){
        int mid = s + (e - s)/2;

        if(arr[mid] > arr[mid + 1]){
            cout << mid + 1 << endl;
            pivot = mid + 1;
            break;
        }

        else if(arr[mid] > arr[0] && arr[mid] > arr[n - 1]){
            s = mid + 1;
        }

        else{
            e = mid - 1;
        }
    }
    cout << pivot << endl;
    return 0;
}