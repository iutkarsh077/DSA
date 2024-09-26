#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*int main()
{
    int val1 = 20;
    int val2 = 40;
    int maxDiv = 1;

    for (int i = min(val1, val2); i >= 1; i--)
    {
        if (val1 % i == 0 && val2 % i == 0)
        {
            maxDiv = i;
            break;
        }
    } 

    cout << "The GCD is: " << maxDiv;
    return 0;
}*/


int main(){
    int a = 20;
    int b = 40;

    while(a > 0 && b > 0){
        if(a <= b){
            b = b % a;
        }
        else{
            a = a % b;
        }
    }

    if(a == 0){
        cout << "The value of b is: " << b;
    }
    else{
        cout << "The value of a is: " << a;
    }
    return 0;
}