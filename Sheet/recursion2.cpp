#include<iostream>
using namespace std;

void printN(int n){
    if(n == 0){
        return;
    }

    printN(n - 1);
    cout << n << " ";
}

int main(){
    printN(10);
    return 0;
}