#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int val()
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


 int maxDepth(string s) {
        int cnt = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt++;
            }

            else if (s[i] == ')') {
                cnt--;
            }

            maxi = max(cnt, maxi);
        }
        return maxi;
    }

int main(){

}