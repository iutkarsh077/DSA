#include <bits/stdc++.h>
using namespace std;

int findHourlyRate(vector<int> arr, int hours)
{
    int hourlyRate = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        hourlyRate += ceil((double)arr[i] / hours);
    }
    return hourlyRate;
}

int main()
{
    vector<int> arr = {30, 11, 23, 4, 20};

    int maxi = INT_MIN;
    int h = 5;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int s = 1;
    int e = maxi;
    int realTime = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        int reqTime = findHourlyRate(arr, mid);
        if (reqTime <= h)
        {
            realTime = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << realTime;
    /*
    for (int i = 1; i <= maxi; i++)
    {
        int reqTime = findHourlyRate(arr, i);
        if (reqTime <= h)
        {
            cout << i;
            break;
        }
    }*/

    return 0;
}
