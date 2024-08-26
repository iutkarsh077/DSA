#include <bits/stdc++.h>
using namespace std;

string replaceSpaces(string &str)
{
    string str2 = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str2.push_back('@');
            str2.push_back('4');
            str2.push_back('0');
            continue;
        }

        else
        {
            str2.push_back(str[i]);
        }
    }

    return str2;
}

int main()
{
    string str = "Coding Ninjas Is A Coding Platform";
    string ch = replaceSpaces(str);
    cout << ch;
    return 0;
}