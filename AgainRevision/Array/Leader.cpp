#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int n, int arr[])
{
    // Code here
    int leader = arr[n - 1];
    vector<int> ans;
    ans.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= leader)
        {
            leader = arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}