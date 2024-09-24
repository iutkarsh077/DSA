#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = i + 1;
        int middle = (2 * n) - (left + right);

        for (int j = 0; j < left; j++)
        {
            cout << "* ";
        }

        for (int j = 0; j < middle; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < right; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        int left = n - i;
        int right = n - i;
        int middle = (2 * n) - (left + right);

        for (int j = 0; j < left; j++)
        {
            cout << "* ";
        }

        for (int j = 0; j < middle; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < right; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}