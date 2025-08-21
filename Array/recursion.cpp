#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printName(int n){
    if(n == 0) return;

    cout << "Utkarsh" << " ";
    printName(n - 1);
}

void printNumber(int n){
    if(n == 0) return;

    printNumber(n - 1);
    cout << n << " ";
}
 
int sumOfNumbers(int n){
    if(n == 0) return 0;

    return n + sumOfNumbers(n - 1);
}

int factorial(int n){
    if(n == 0) return 1;

    return n * factorial(n - 1);
}

void reverse(int i, int j, vector<int> &nums){
    if(i >= j) return;

    swap(nums[i], nums[j]);

    reverse(i + 1, j - 1, nums);
}

bool palindrome(string val, int i, int j){
    if(i >= j) return true;

    if(val[i] != val[j]){
        return false;
    } 

    return palindrome(val, i + 1, j - 1);
}

int fibo(int n){
    if(n <= 1)  return n;

    return fibo(n - 1) + fibo(n - 2);
}

int main(){

    cout << fibo(6);
    return 0;
}