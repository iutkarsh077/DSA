#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};

    int i = 0;
    int max_sum = 0;
    int k = 4;
    while (i < k)
    {
        int j = 0;
        int sum = 0;

        while (j <= i)
        {
            sum = sum + arr[j];
            j++;
        }

        int l = j;

        while (l < k)
        {
            sum = sum + arr[arr.size() - (k - l)];
            l++;
        }

        max_sum = max(sum, max_sum);
        i++;
    }

    cout << max_sum;
    return 0;
}