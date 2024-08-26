#include <bits/stdc++.h>
using namespace std;

int main()
{
    string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "xyz"};

    string val = "23";
    vector<string> temp;
    string b = arr[val[0] - '0'];
    string c = arr[val[1] - '0'];
    for (int i = 0; i < b.size(); i++)
    {
        string a;
        for (int j = 0; j < c.size(); j++)
        {
            a += b[i];
            a += c[j];
        }
        temp.push_back(a);
    }

    int i = 0;
    while (i < temp.size())
    {
        cout << temp[i] << " ";
        i++;
    }
    return 0;
}