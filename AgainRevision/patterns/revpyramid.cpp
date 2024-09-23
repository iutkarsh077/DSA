#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < (5 + 5) - i; j++)
        {
            if (j <= i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}