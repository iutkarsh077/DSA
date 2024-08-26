#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            if (i + j < n + 1)
            {
                cout << " "
                     << " ";
            }
            else
            {
                cout << '*' << " ";
            }
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}