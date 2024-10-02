#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 1;
    while (i < n)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}