#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    int val = 65;
    while(i <= n){
        int j = 0;
        while(j <= i){
            cout << char(val) << " ";
            val++;
        j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}