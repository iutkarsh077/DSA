#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> v = {4, 1,2 ,3, 1};

    unordered_map<int, int> m;

    for(int i = 0; i < v.size(); i++){
        m[v[i]] = i;
    }

    for(auto x : m){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}