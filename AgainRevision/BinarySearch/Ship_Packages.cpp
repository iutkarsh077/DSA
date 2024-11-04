#include <bits/stdc++.h>
using namespace std;

int findLoad(vector<int> arr, int cap)
{
    int i = 0;
    int load = 0;
    int day = 1;
    for(int i = 0; i < arr.size(); i++){
        if(load + arr[i] > cap){
            day = day + 1;
            load = arr[i];
        }

        else{
             load += arr[i];
        }
    }

    return day;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }

    int s = maxi;
    int e = sum;
    int days = 5;
    int minCapacity = 0;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        int reqVal = findLoad(arr, mid);

        if(reqVal <= days){
            minCapacity = mid;
            e = mid - 1;
        }

        else if(reqVal > days){
            s = mid + 1;
        }

       
    }

    cout << minCapacity;
    return 0;
}