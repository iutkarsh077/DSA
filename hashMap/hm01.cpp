#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> mp;

    pair<string, int> p1("Hey", 1);
    mp.insert(p1);

    pair<string, int> p2("there", 9);
    mp.insert(p2);

    pair<string, int> p3("arsh", 3);
    mp.insert(p3);

    pair<string, int> p4("singh", 5);
    mp.insert(p4);


    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    cout << mp.size();
    return 0;
}