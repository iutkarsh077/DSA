#include <bits/stdc++.h>
using namespace std;

void patterns()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*" << " ";
        }

        for (int j = 0; j < i * 2; j++)
        {
            cout << "_" << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << "*" << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (; j <= i; j++)
        {
            cout << "*" << " ";
            
        }

        for (; j < (n * 2) - i - 1; j++)
        {
            cout << "_" << " ";
         
        }

        for(; j < (n * 2); j++){
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