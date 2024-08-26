#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {5,  2, 9, 7, 6, 1, 0};
    int n = 7;
    for (int i = 0; i < n - 1; i = i + 2)
    {
        if (i + 1 >= n)
            break;
        swap(arr[i], arr[i + 1]);
    }


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}