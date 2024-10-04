#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    set<int> s1;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        s1.insert(arr[i]);
    }

    for(auto i = s1.begin(); i != s1.end(); i++){
        cout << *i << " ";
    }
    return 0;
}