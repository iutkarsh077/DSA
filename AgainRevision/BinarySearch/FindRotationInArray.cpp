#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int mini = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mini > arr[i])
        {
            mini = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main()
{
    return 0;
}