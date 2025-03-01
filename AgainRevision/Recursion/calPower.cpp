#include <bits/stdc++.h>
using namespace std;

int CalPower(int a, int b){
    if(b <= 0) return 1;

    if(b % 2 == 0){
        return  CalPower(a, b/2) * CalPower(a, b/2);
    }
    else{
        return a * CalPower(a, b/2) * CalPower(a, b/2);
    }
}

int main() {
    int a, b;
    cout << "Enter the value: ";
    cin >> a;
    cout << endl;
    cout << "Enter the Power: ";
    cin >> b;
    cout << endl;
    cout << CalPower(a, b);

    return 0;
}