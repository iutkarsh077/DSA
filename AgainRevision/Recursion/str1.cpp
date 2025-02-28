#include<iostream>
using namespace std;


void printVal(string val, int i){
    if(i < 0) return;

    cout << val[i];

    printVal(val, i - 1);
}

int main(){
    string val = "abcde";
    printVal(val, val.length() - 1);
    return 0;
}