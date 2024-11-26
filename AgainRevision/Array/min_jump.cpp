#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> arr = {1, 10, 20};

    int jump = 0;
    int i = 0;

    while (i < arr.size() - 1)
    {
        if (arr[i] == 0) return 0;

        int j = i;
        int maxi = -1;

        while (j <= i + arr[i] && j < arr.size())
        {
            maxi = max(arr[j], maxi);
            j++;
        }

        jump++;
        i = maxi + j;
    }

    

    cout << jump;
    return 0;
}