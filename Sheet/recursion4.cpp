#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n - 1);
}

void reachSchool(int src, int dest){
    if(src == dest){
        cout << "Reached School" << endl;
        return;
    }

    cout << "Covered distance: " << src << endl;

    reachSchool(src + 1, dest);
}

void fibo(int n, int first, int second){
    if(n == 2) return;

    int sum = first + second;
    cout << sum << " ";
    first = second;
    second = sum;

    return fibo(n - 1, first, second);
}

void fiboIterative(int n){
    int first = 0;
    int second = 1;

    for(int i = 3; i <= n; i++){
        int sum = first + second;
        cout << sum << " ";

        first = second;
        second = sum;
    }
}

int main(){
    cout << 0 << " " << 1 << " ";
    fibo(8, 0, 1);
    return 0;
}