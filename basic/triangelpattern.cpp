#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 1;
    int n;
    cin >> n;
    int count = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout << count << ' ';
            j = j + 1;
            count = count  + 1;
        }
        i = i + 1;
        cout << endl;
    }
    return 0;
}