#include<bits/stdc++.h>
using namespace std;

long long sumOfSeries(long long n){
    if(n == 1){
        return 1;
    }

    return pow(n, 3) + sumOfSeries(n - 1);
}

 vector<long long> factorialNumbers(long long n) {
        long long val = 1;
    long long cnt = 1;
    vector<long long> ans;
    
    while (val <= n) {
        ans.push_back(val);
        cnt++;
        if (val > n / cnt) break; // Prevent overflow
        val *= cnt;
    }
    
    return ans;    }
int main(){
    long long n = 6;
    // long long ans = sumOfSeries(n);
    // cout << ans;
    vector<long, long> ans = factorialNumbers(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}