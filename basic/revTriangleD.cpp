#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int val = 65;
    int i = 0;
    while(i < n){
        int j = 0;
        while(j <= i){
            cout << char(val + n - i - 1 + j) << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}