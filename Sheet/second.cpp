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

    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int i = 0;
        while(i < nums.size() - 1){
            if(nums[i] != nums[i + 1]){
                return nums[i];
            }
            else{
                i = i + 2;
            }
        }

        if(nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1];
        }

        return -1;
    }

     long long calculateHours(vector<int> piles, int h) {
        long long totalHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalHours += ceil((double)(piles[i]) / (double)(h));
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles.size();

        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        for (int i = 1; i <= maxi; i++) {
            long long cal = calculateHours(piles, i);
            if (cal <= h) {
                return i;
            }
        }

        return maxi;
    }

     int singleNonDuplicateBinary(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];
        int s = 1;
        int e = nums.size() - 2;

        while (s <= e) {
            int mid = s + ((e - s) / 2);

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            else if (nums[mid] == nums[mid - 1]) {
                if ((mid - 1) % 2 == 0) {
                    s = mid + 1;
                }

                else {
                    e = mid - 1;
                }
            }

            else if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        if(nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1];
        }

        return -1;
    }

int main(){
     int ans = 8.7;
    cout << ans;
    return 0;
}