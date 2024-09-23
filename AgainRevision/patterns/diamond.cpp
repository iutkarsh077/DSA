#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 0; i < (2 * n) - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i < n - 1)
            {
                cout << "*" << " ";
            }
        }
        cout << endl;
    }
    return 0;
}