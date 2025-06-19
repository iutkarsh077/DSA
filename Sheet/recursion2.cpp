#include<iostream>
using namespace std;

void printN(int n){
    if(n == 0){
        return;
    }

    printN(n - 1);
    cout << n << " ";
}

int facto(int n){
    if(n == 1) return 1;

    return n * facto(n - 1);
}

int main(){
    int ans = facto(10);
    cout << ans << endl;
    return 0;
}