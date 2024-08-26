#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 1, 7, 5, 8, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int min_val = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_val] > arr[j])
            {
                min_val = j;
            }
        }
        swap(arr[min_val], arr[i]);
    }

    int i = 0; 
    while(i < n){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}