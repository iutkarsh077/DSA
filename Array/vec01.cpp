#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int v[] = {4, 1,2 ,3, 1};
    vector<int> v2(v, v+ 5);

    int i = 0;

    while(i < v2.size()){
        cout << v2[i] << " ";
        i++;
    }
    return 0;
}