#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 90;
    int &j = i;
    cout <<  &i;
    cout << endl << &j;
    i++;
    cout << endl << j;
    return 0;
}