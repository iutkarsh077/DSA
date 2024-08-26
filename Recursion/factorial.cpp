#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }

    int myval = n * factorial(n - 1);
    return myval;
}

int main()
{
   int val = factorial(10);
   cout << val;
    return 0;
}