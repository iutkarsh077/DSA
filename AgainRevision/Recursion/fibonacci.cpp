#include<iostream>
using namespace std;


int fibo(int i){
    if(i == 0){
        return 0;
    }

    if(i == 1){
        return 1;
    }

    return fibo(i - 1) + fibo(i - 2);
}

int main(){
    int result = fibo(8 );
    cout << result;
    return 0;
}