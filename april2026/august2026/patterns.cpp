#include <bits/stdc++.h>
using namespace std;

void patterns()
{
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " " << " ";
        }

        int starsCount = (2 * (n - i)) - 1;
        for (int j = 0; j < starsCount; j++)
        {
            cout << "*" << " ";
        }

        cout << endl;
    }
}

int main()
{
    patterns();
    return 0;
}