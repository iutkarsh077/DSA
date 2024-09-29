#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }


    for(int i = 0; i < arr.size(); i++){
        arr[i] = 0;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        arr[i->first - 1] = i->second;
    }

    for(int i = 0; i < arr.size(); i++){
        cout << "Value of " << i  << " is: " << arr[i] << " ";
        cout << endl;
    }

    return 0;
}