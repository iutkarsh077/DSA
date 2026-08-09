#include <bits/stdc++.h>
using namespace std;

void patterns()
{
    int n = 4;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << "_" << " ";
        }

        int val = 65;
        for(int j = 0; j <= i; j++){
            cout << char(val) << " ";
            val++;
        }

        val = val - 2;
        for(int j = 0; j < i; j++){
            cout << char(val) << " ";
            val--;
        }

        cout << endl;
    }
    
}

int main()
{
    patterns();
    return 0;
}