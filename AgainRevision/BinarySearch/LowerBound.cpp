#include <bits/stdc++.h>
using namespace std;

int BruteMethode(vector<int> arr)
{
    int x = 13;
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= x)
        {
            maxi = max(maxi, i);
        }

        else if (arr[i] > x)
        {
            break;
        }
    }
    cout << maxi;
    return 0;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int x = 20;

    int s = 0;
    int e = arr.size() - 1;
    int index = -1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (arr[mid] == x)
        {
            index = mid;
            break;
        }

        else if (arr[mid] < x)
        {
            index = mid;
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    cout << "Index is: " << index;
    return 0;
}