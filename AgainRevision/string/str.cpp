#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "Utkarsh";
    cout << name.length() << endl;
    cout << name[2] << endl;
    name += 'i';
    cout << name << endl;
    if (name == "Utkarshi")
    {
        cout << "true";
    }
    cout << endl;
    string str2 = name.substr(3, 2);
    cout << str2 << endl;
    return 0;
}