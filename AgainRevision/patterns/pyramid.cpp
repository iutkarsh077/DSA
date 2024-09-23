#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 + i; j++)
        {
            if (i + j >= 5)
            {
                cout << "*";
            }
            else
            {
                cout << "_";
            }
        }
        cout << endl;
    }
    return 0;
}