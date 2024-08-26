#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {-3, 0, 1, -3, 1, 1, -3, 10, 0};
    map<int, int> mp;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for(auto j = mp.begin(); j != mp.end(); j++){
            if(i->first == j->first) continue;
            else if(i->second == j->second) {
                cout << "Have similar values";
                return 0;
            }
        }
    }
    cout << endl;
    cout << "They does not have similar values";
    return 0;
}