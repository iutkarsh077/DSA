#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    int arr[] = {2, 1, 7, 5, 8, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}*/



int main(){
     int arr[] = {2, 1, 7, 5, 8, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}