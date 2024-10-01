#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int MaximumFrequent(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = 0;
    int total = 0;
    int result = 0;
    int k = 5;

    while (right < arr.size())
    {
        total = total + arr[right];

        while (arr[right] * (right - left + 1) > total + k)
        {
            total -= arr[left];
            left++;
        }
        result = max(result, right - left + 1);
        right += 1;
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 4, 8, 13};
    int val = MaximumFrequent(arr);
    cout << val;
    return 0;
}