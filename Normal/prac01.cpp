//Find Prime number
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 4;
    int cnt = 0;
    // for(int i = 1; i <= n; i++){
    //     if(n % i == 0){
    //         cnt++;
    //     }
    // }

    // if(cnt == 2) cout << "Yes it is a Prime number";
    // else{
    //     cout << "No, it is not a prime Number";
    // }

    int hey = sqrt(n);

    for(int i = 1; i <= hey; i++){
        if(n % i == 0){
            cnt++;
            if(n / i != i){
                cnt++;
            }
        }
        if(cnt > 2){
            break;
        }
    }

    if(cnt == 2){
        cout << "yes";
    }
    else{
        cout << "No";
    }
    return 0;
}