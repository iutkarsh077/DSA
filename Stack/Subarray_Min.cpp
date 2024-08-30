#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallElement(vector<int> nums) {
    vector<int> result(nums.size(), -1);
    stack<int> st;

    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    vector<int> result = prevSmallElement(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
