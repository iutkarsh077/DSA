#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 5, 1, 10, 10};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 14;
    int l = 0;
    int r = 0;
    int max_len = 0;
    int sum = 0;

    while (r < n)
    {
        sum += arr[r];

        while (sum > k)
        {
            sum -= arr[l];
            l = l + 1;
        }
        if (sum <= k)
        {
            max_len = max(max_len, sum);
        }
        r =  r + 1;
    }
    cout << max_len;
    return 0;
}

/**    int max_sum = 0;
   for (int i = 0; i < k; i++) {
       sum += arr[i];
   }

   while(r < n) {
       sum -= arr[l];
       l++;
       sum += arr[r];
       r++;
       max_sum = max(max_sum, sum);
   }

   cout << max_sum << endl;**/