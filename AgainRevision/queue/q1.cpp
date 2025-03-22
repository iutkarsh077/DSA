#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    for(int i = 1; i <= 10; i++){
        q.push(i);
    }

    swap(q.front(), q.back());
    q.pop();
    cout << q.back() << endl;
    cout << q.front() << endl;
}