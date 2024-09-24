#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;

    // First half of the pattern
    for (int i = 0; i < n; i++)
    {
        int left = n - i;
        int right = n - i;
        int middle = (2 * n) - (left + right);

        // Print left stars
        for (int j = 0; j < left; j++)
        {
            cout << "* ";
        }

        // Print middle spaces
        for (int k = 0; k < middle; k++)
        {
            cout << "  ";  // Two spaces for better symmetry
        }

        // Print right stars
        for (int m = 0; m < right; m++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Second half of the pattern
    for (int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = i + 1;
        int middle = (2 * n) - (left + right);

        // Print left stars
        for (int j = 0; j < left; j++)
        {
            cout << "* ";
        }

        // Print middle spaces
        for (int j = 0; j < middle; j++)
        {
            cout << "  ";  // Two spaces for symmetry
        }

        // Print right stars
        for (int j = 0; j < right; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
