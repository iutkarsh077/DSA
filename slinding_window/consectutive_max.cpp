#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 2;
    int max_len = 0;
    int zero_count = 0;
    int n = sizeof(nums) / sizeof(nums[0]);
    int left = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero_count++;
        }

        while (zero_count > k) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }

        max_len = max(max_len, i - left + 1);
    }

    cout << max_len << endl;
    return 0;
}
