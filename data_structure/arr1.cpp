#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    arr.pop_back();
    arr.push_back(32);
    arr.clear();

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl << arr.front() << endl;
    cout << arr.back() << endl;
    cout << arr.empty() << endl;
    return 0;
}