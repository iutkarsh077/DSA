#include <bits/stdc++.h>
using namespace std;

/*int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> nums3;

    for (int i = 0; i < nums1.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums2[j] == nums1[i])
            {
                for (int k = j; k < nums2.size(); k++)
                {
                    if (nums2[k] > nums1[i])
                    {
                        nums3.push_back(nums2[k]);
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    nums3.push_back(-1);
                }
            }
            if (flag == false)
            {
                break;
            }
        }
    }

    int i = 0;
    while (i < nums3.size())
    {
        cout << nums3[i] << " ";
        i++;
    }
    return 0;
}*/

/*int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> nums3;
    map<int, int> mpp;

    for (int i = 0; i < nums2.size(); i++)
    {
        mpp[nums2[i]] = i;
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        bool flag = true;

        int val = mpp[nums1[i]];
        for (int j = val; j < nums2.size(); j++)
        {
            if (nums2[j] > nums1[i])
            {
                nums3.push_back(nums2[j]);
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            nums3.push_back(-1);
        }
    }

    int i = 0;

    while (i < nums3.size())
    {
        cout << nums3[i] << " ";
        i++;
    }
}*/

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> nums3(nums2.size(), -1); // Initialize nums3 with -1
    stack<int> st;

    for(int i = nums2.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        if(!st.empty()) {
            nums3[i] = st.top();
        }

        st.push(nums2[i]);
    }

    for(int i = 0; i < nums3.size(); i++) {
        cout << nums3[i] << " ";
    }
    cout << endl;

    return 0;
}