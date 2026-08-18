#include<bits/stdc++.h>
using namespace std;

void pairme(){
    pair<int, pair<int, int>> p = {1, {2, 3}};


    cout << p.second.second;
}

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second > p2.second) return false;
    if(p1.second < p2.second) return true;

    if(p1.first > p2.first) return true;
    return false;
}

void myset(){
    set<int, greater<int>> s1 = {4, 1, 3, 2, 5, 6};
    s1.insert(20);
    s1.erase(1);

    for(auto i = s1.begin(); i != s1.end(); i++){
        cout << *(i) << " ";
    }

    cout << endl;
    cout << s1.size() << endl;

    auto it =  s1.find(90);

    cout << *it;


    pair<int, int> mp[] = {{2, 3}, {4, 5}, {3, 2}};

    sort(mp, mp + 3, comp);
}

void iter(){
    vector<int> v = {10, 20, 30, 40};

    v.insert(v.begin(), {1, 2, 3});

    for(auto i = v.begin(); i != v.end(); i++){
        cout << *(i) << " ";
    }
}


int main(){
    // pairme();
    myset();
    return 0;
}
