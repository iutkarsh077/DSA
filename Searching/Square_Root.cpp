#include <bits/stdc++.h>
using namespace std;

int main() {
    int val = 4563;
    int ans = 0;
    
    int s = 1;
    int e = val;

    while(s <= e){
        long long int mid = s + (e - s)/2;

        if(mid * mid <= val){
            ans = mid;
            s = mid + 1;
        }

        else {
            e = mid - 1;
        }
    }
    cout << ans;

    return 0;
}