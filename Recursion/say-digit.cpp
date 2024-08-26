#include <bits/stdc++.h>
using namespace std;

void sayDigit(int n){
    if(n <= 0){
        return;
    }

    string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    int val = n % 10;
    n = n / 10;
    sayDigit(n);
    cout << arr[val] << " ";
}

int main()
{
    int n;
    cin >> n;
    sayDigit(n);
    return 0;
}