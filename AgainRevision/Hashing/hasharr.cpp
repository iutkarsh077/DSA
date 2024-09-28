#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> num = {1, 3, 2, 1, 3};
    vector<int> arr(num.size(), 0);

    for(int i = 0; i < num.size(); i++){
        arr[num[i]] += 1; 
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}