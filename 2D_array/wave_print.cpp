#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][4] = {
        {0, 1, 2, 3},
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6}};

    cout << sizeof(arr) / sizeof(arr[0]) << endl;

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int j = 3; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}