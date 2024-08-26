#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s1;

    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout << "Top: " << s1.top() << endl;
    while(!s1.empty()){
        cout <<  s1.top() << " ";
        s1.pop();
    }
    return 0;
}