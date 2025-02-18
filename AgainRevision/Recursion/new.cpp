#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool result(int n, int index){
	
	if(index == n/2)   return true;

	if(n % index == 0) return false;

	return result(n, index + 1);
}

bool isPrime(int n)
{
	if(n == 1){
		return false;
	}
	bool ans = result(n, 2);
	return ans;
}

double myPow(double x, int n)
{
    if (x == 0)
    {
        return 0;
    }

    double result = 1;
    long long int duplicate = n;

    if (duplicate < 0)
    {
        duplicate = -duplicate;
        x = 1 / x;
    }

    while (duplicate > 0)
    {
        if (duplicate % 2 == 1)
        {
            result *= x;
        }

        x *= x;
        duplicate /= 2;
    }
    return result;
}

int main()
{
    return 0;
}

int main()
{
    int x = 2;
    int n = 10;
    double ans = pow(2, -2);
    cout << ans;
    return 0;
}