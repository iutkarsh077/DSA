#include <bits/stdc++.h>
using namespace std;

int main()
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
}