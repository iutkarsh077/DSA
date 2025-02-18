#include <bits/stdc++.h>
using namespace std;

int printNumbers(int n, int i)
{
    if (i >= n)
    return n;

    cout << i << endl;
    return printNumbers(n, i + 1);
}

int main()
{
    int result = printNumbers(10, 1);

    cout << endl;
    cout << endl;
    cout << result;
    return 0;
}