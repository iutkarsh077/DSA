#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;
    int arr[9] = {1, 3, 1, 3, 6, 6, 7, 98, 7};
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int val = -1;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if(i->second == 1){
            val = i->first;
            break;
        }
    }

    cout << val;
    return 0;
}