#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >>n;
    int i = 0;
    int val = 65;
    while(i < n){
        int j = 0;
        while(j < n){
            cout << char(65 + i + j) << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}