#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 1};
    int k = 2;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                if (sum == k)
                {
                    cnt++;
                    break;
                }
            }
        }

    cout << "Number of subarrray is: " << cnt;
    return 0;
}