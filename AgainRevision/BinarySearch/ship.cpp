#include <bits/stdc++.h>
using namespace std;


int findDaysBrute(vector<int> weights, int cap){
    int days = 1;
    int load = 0;

    for(int i = 0; i < weights.size(); i++){
        if(load + weights[i] > cap){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }

    return days;
}

long long int findDays(vector<int> weights, int cap) {
        int days = 1;
        long long int load = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        int s = maxWeight;
        int e = sum;
        int ans = -1;

        while(s <= e){
            int mid = s + ((e - s)/2);
            int val = findDays(weights, mid);

            if(val <= days){
                ans = mid;
                e = mid - 1;
            }

            else{
                s = mid + 1;
            }
        }

        
        return ans;
    }

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int maxWeight = 10;
    int sum = 55;
    for(int i = maxWeight; i <= sum; i++){
        int val = findDays(weights, i);
        if(val <= days){
            cout << i;
            break;
        }
    }
    return 0;
}