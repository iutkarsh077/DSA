#include <bits/stdc++.h>
using namespace std;

int findLoad(vector<int> arr, int mid, int days)
{
    int i = 0;
    int sum = 0;

    while (i < arr.size())
    {
        if (sum >= mid)
        {
            days--;
        }

        else
        {
            sum = sum + arr[i];
            i++;
        }
    }

    if (days == 0)
    {
        return mid;
    }

    return days;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int maxi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi += arr[i];
    }

    int s = 0;
    int e = maxi;
    int days = 5;
    int minCapacity = 0;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        int reqVal = findLoad(arr, mid, days);

        if(reqVal > 0){
            minCapacity = reqVal;
            e = mid - 1;
        }

        else if(reqVal == 0){
            minCapacity = reqVal;
            s = mid + 1;
        }

       
    }

    cout << minCapacity;
    return 0;
}