#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 8, 7, 90, 56};
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    cout << largest;
    return 0;
}