#include <bits/stdc++.h>
using namespace std;

class OneToN
{
public:
    void printOne(int n, int i)
    {
        if (i == n)
        {
            cout << n;
            return;
        }

        cout << i << " ";
        printOne(n, i + 1);
    }
    void printNos(int n)
    {
        printOne(n, 1);
        return;
    }

    void printMe(int n, int i)
    {
        if (i == n)
        {
            cout << "GFG" << " ";
            return;
        }

        cout << "GFG" << " ";
        printMe(n, i + 1);
    }
    void printGfg(int N)
    {
        printMe(N, 1);
    }

    long long myDigitSum(long long n, long long sum, long long i)
    {
        if (i > n)
        {
            return sum;
        }

        long long ans = i * i * i;
        sum = sum + ans;
        i = i + 1;
        return myDigitSum(n, sum, i);
    }
};

int main()
{
    OneToN obj;
    long long result = obj.myDigitSum(5, 0, 1);
    cout << result;
    return 0;
}