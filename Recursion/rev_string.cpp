#include <bits/stdc++.h>
using namespace std;

void Reverse(string &name, int i, int j)
{
    if (i >= j)
    {
        return;
    }

    swap(name[i], name[j]);
    i = i + 1;
    j = j - 1;
    Reverse(name, i, j);
}

int main()
{
    string name = "Babbar";
    string revName = "";
    int j = name.size() - 1;
    Reverse(name, 0, j);
    cout << name;
    return 0;
}