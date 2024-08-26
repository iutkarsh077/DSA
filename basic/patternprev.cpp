#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    while(i <= n){
        int j = 0;
        while(j <= i){
            cout << j + i + 1 << " ";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}