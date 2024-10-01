#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i; j < n; j++)
        {
            if (arr[max] > arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            swap(arr[max], arr[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}