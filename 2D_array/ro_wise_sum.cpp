#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][4] = {
        {0, 1, 2, 3},
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6}};

    int brr[4];

    for(int i = 0; i < 4; i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            sum = sum + arr[i][j];
        }
        brr[i] = sum;
    }

    for(int i = 0; i < 4; i++){
        cout << brr[i] << " ";
    }
    return 0;
}