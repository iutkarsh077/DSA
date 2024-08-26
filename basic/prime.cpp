#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;

    for(int i = 1; i < a; i++){
        if(a % 2 == 0){
            cout << "Not Prime Number" << endl;
            return 0;
        }
    }

    cout << "Prime Number" << endl;
    return 0;
}