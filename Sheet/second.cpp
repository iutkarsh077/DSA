#include<bits/stdc++.h>
using namespace std;


int mySqrt(int x) {
        int s = 0;
        int e = x;

        while (s <= e) {
            int mid = s + ((e - s) / 2);

            long long square = static_cast<long long>(mid) * mid;
            

            if (square == x){
                 return mid;
            }
            else if (square > x) {
                e = mid - 1;
            }

            else {
                s = mid + 1;
            }
        }

        return static_cast<int>(std::round(e));
    }


     int nthRoot(int n, int m) {
        // Code here.
        if(n == 1) return m;
        
        int s = 1;
        int e = m;
        
        while(s <= e){
            int mid = s +((e - s)/2);
            
            long long val = pow(mid, n);
            
            if(val == m) return mid;
            
            else if(val > m){
                e = mid - 1;
            }
            
            else{
                s = mid + 1;
            }
        }
        
        return -1;
    }

int main(){
     int ans = 8.7;
    cout << ans;
    return 0;
}