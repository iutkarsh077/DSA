#include <iostream>
#include<math.h>
using namespace std;

double myPow(double x, int n)
{
    double ans = pow(x, n);
    return ans;
}

 double ansPow(double x, int n){
        if(n == 1) return x;
        if(n == 0) return 1;

        if(n % 2 == 0){
            return ansPow(x, n / 2) * ansPow(x, n / 2);
        }
        else{
            return x * ansPow(x, n / 2) * ansPow(x, n / 2);
        }
    }

    double myPow(double x, int n) {
        return ansPow(x, n);
    }

int main()
{
    return 0;
}