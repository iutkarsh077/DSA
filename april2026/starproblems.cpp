#include<bits/stdc++.h>
using namespace std;

void RectangleStar(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << '*';
        }
        cout << endl;
    }
}


void Triangle1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << '*';
        }
        cout << endl;
    }
}

int main(){
    Triangle1(10);
    return 0;
}