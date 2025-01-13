#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s = "ab";
    if(s.size() == 0){
        return -1;
    }
    map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    int maxi = INT_MIN;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxi = max(i->second, maxi);
    }

    string ans = "";
    int i = maxi;

    while (i > 0)
    {
        bool flag = true;
        for (auto j = mp.begin(); j != mp.end(); j++)
        {
            if (j->second == i)
            {
                for (int k = 0; k < i; k++)
                {
                    flag = false;
                    ans += j->first;
                }
                mp.erase(j->first);
                break;
            }
        }
        if(flag == true){
            i--;
        }
    }

    cout << ans;
    return 0;
}