#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

//  int lenOfLongSubarr(int A[],  int N, int K)
//     {
//         // Complete the function
//         int maxi = 0;
//         for(int i = 0; i < N; i++){
//             int cnt = 0;
//             int sum = 0;
//             for(int j = i; j < N; j++){
//                 sum = sum + A[j];
//                 cnt++;

//                 if(sum == K){
//                     cout << "The count is: " << cnt << endl;
//                     maxi = max(cnt, maxi);
//                     // break;
//                 }

//                 // if(sum > K){
//                 //     break;
//                 // }
//             }
//         }
//         return maxi;
//     }

// int main() {
//     int arr[] = {-14, 10, -15, 17, 4, 18, 3, -18, -7, -4, -8, 8, -8};
//     int N = sizeof(arr)/sizeof(arr[0]);

//     int val = lenOfLongSubarr(arr, N, 12);
//     cout << val;
//     return 0;
// }

// int main(){
//     map<long long, int> mp;
//    mp.insert(make_pair(4, 0));
//     mp.insert(make_pair(5, 1));
//     mp.insert(make_pair(6, 2));

//     int rem  = 5;
//     if(mp.find(rem) != mp.end()){
//         cout << mp[rem];
//     }
//     // for(auto i = mp.begin(); i != mp.end(); i++){
//     //     cout << i->second << " ";
//     // }
//     return 0;
// }

// int main()
// {
//     map<long long, int> mp;
//     int arr[] = {2, 0, 0, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int k = 3;
//     int sum = 0;
//     int maxi = 0;
//     for(int i = 0; i < n; i++){
//         sum = sum + arr[i];

//         if(sum == k){
//             maxi = max(maxi, i + 1);
//         }

//         long long rem = sum - k;
//         if(mp.find(rem) != mp.end()){
//             int len = i - mp[rem];
//             maxi = max(maxi, len);
//         }

//         if(mp.find(sum) == mp.end()){
//             mp[sum] = i;
//         }
//     }

//     cout << "The maxi subarray is: " << maxi;
//     return 0;
// }

int main()
{
    int arr[] = {2, 0, 0, 3, -1, -1};
    map<long long, int> mp;
    long long sum = 0;
    int maxi = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = -2;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];

        if(sum == k){
            maxi = max(maxi, i + 1);
        }

        long long rem = sum - k;
        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            maxi = max(maxi, len);
        }

        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }

    }
    cout << "The longest subarray is: " << maxi;
    return 0;
}