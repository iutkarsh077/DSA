#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int largest = arr[0];
    int secLargest = INT_MIN;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (largest < arr[i])
        {
            secLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secLargest){
            secLargest = arr[i];
        }
    }

    cout << largest << endl;

    cout << secLargest << endl;
    return 0;
}