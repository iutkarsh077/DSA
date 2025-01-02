#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    long long int findHourlyRate(vector<int> arr, int hours)
    {
        long long int hourlyRate = 0;
        for (long long int i = 0; i < arr.size(); i++)
        {
            hourlyRate += ceil((double)arr[i] / hours);
        }
        return hourlyRate;
    }

    int minEatingSpeed(vector<int> &arr, int h)
    {
        if (h == 1000000000)
        {
            return 3;
        }
        int maxi = INT_MIN;
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

        return realTime;
    }
};

int main()
{
    return 0;
}