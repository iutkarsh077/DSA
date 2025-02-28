#include<iostream>
using namespace std;


void printVal(string val, int i){
    if(i < 0) return;

    cout << val[i];

    printVal(val, i - 1);
}


void rev(string &str, int i){
    if(i >= str.length() - i - 1) return;

    swap(str[i], str[str.length() - i - 1]);
    rev(str, i + 1);
}

string reverseString(string str)
{
	rev(str, 0);

    return str;
}

int main(){
    string val = "abcde";
    printVal(val, val.length() - 1);
    return 0;
}