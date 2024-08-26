#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 138;
    string result = "";

    while(n != 0){
        char val = (n % 2) + '0';
        result  += val;
        n = n / 2;
    }

    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}

// Time Complexity -> O(log n) same for SC