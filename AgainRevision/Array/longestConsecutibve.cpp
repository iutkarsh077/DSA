#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 0, 1};
    sort(arr.begin(), arr.end());

    int cnt = 1;
    int maxi = 1;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            continue;
        }

        else if (arr[i] + 1 == arr[i + 1])
        {
            cnt++;
            maxi = max(maxi, cnt);
        }

        else
        {
            cnt = 1;
        }
    }

    cout << "Lonest consecutive is: " << maxi;
    return 0;
}