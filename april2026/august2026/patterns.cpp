#include <bits/stdc++.h>
using namespace std;

void patterns()
{
    int n = 5;
    int val = 65;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cout << char(val) << " ";
        }
        val++;
        cout << endl;
    }
}

int main()
{
    patterns();
    return 0;
}