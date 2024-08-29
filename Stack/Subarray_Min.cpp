#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2};
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int mini = arr[i];
        for (int j = i; j < arr.size(); j++)
        {
            mini = min(arr[j], mini);
            sum = sum + mini;
        }
    }
    cout << sum << endl;
    return 0;
}