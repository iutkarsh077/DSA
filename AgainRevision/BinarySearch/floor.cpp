#include <bits/stdc++.h>
using namespace std;

int findFloorBrute(vector<int> &arr, int k)
{
    int floorVal = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            floorVal = i;
        }
        else
        {
            break;
        }
    }

    return floorVal;
}




int main()
{
    return 0;
}