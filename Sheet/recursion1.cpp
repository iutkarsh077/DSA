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


     double ansPowNeg(double x, int n) {
        if (n == 1)
            return x;
        if (n == 0)
            return 1;

         double half = ansPowNeg(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }

    double myPowNeg(double x, int n) {
        long nn = n;
        if (n < 0) {
            nn = -1 * nn;
            return 1.0 / ansPowNeg(x, nn);
        }
        return ansPowNeg(x, nn);
    }

int main()
{
    return 0;
}