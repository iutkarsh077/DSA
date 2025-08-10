#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include<climits>
using namespace std;

vector<int> twoSumBrute(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }

    return {-1, -1};
}

vector<int> twoSumBetter(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];
        if (mp.find(need) != mp.end())
        {
            return {i, mp[need]};
        }
        mp.insert({nums[i], i});
    }
    return {-1, -1};
}

vector<int> mySumRecursive(vector<int> &nums, int target, unordered_map<int, int> &mp, int i)
{
    if (i == nums.size())
        return {};

    int need = target - nums[i];
    if (mp.find(need) != mp.end())
    {
        return {i, mp[need]};
    }

    mp[nums[i]] = i;
    i = i + 1;
    return mySumRecursive(nums, target, mp, i);
}

int slideWindow(vector<int> nums, int k)
{
    int l = 0;
    int r = k - 1;
    int maxi = 0;

    while (r < nums.size())
    {
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum = sum + nums[i];
        }

        maxi = max(sum, maxi);
        l++;
        r++;
    }

    cout << "Max Value is: " << maxi << endl;
}

void DS()
{
    vector<int> nums = {2, 5, 1, 10, 10};
    int k = 14;
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxi = 0;

    while (r < nums.size())
    {
        sum = sum + nums[r];

        while (sum > k)
        {
            sum = sum - nums[l];
            l = l + 1;
        }

        if (sum <= k)
        {
            maxi = max(maxi, sum);
            r++;
        }
    }

    cout << "Max consecutive sum is: " << maxi;
}

void DSFrontBack()
{
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    int n = arr.size();
    int l = arr.size() - k;
    int r = l + k - 1;
    int cnt = 0;
    int maxi = 0;
    while (cnt <= k)
    {
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            int dup = i % n;
            sum = sum + arr[dup];
        }

        maxi = max(maxi, sum);
        cnt = cnt + 1;
        l = l + 1;
        r = r + 1;
    }

    cout << "Max value is: " << maxi;
}

int longestSubStr()
{
    string s = "cadbzabcd";
    int n = s.size();
    int maxLen = 0;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mp;

        for (int j = i; j < n; j++)
        {
            if (mp[s[j]] == 1)
                break;

            int len = j - i + 1;
            if (len > maxLen)
            {
                maxLen = max(maxLen, len);
                ans = s.substr(i, j - i + 1);
            }

            mp[s[j]] = 1;
        }
    }

    cout << "Longest sub string is: " << maxLen << " " << ans;
}

int betterLongestStr()
{
    string s = "cadbzabcd";
    unordered_map<int, int> mp;
    int n = s.size();
    int l = 0;
    int r = 0;
    int maxLen = 0;

    while (r < s.size())
    {
        if (mp[s[r]] != -1)
        {
            if (mp[s[r]] >= l)
            {
                l = mp[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        maxLen = max(len, maxLen);
        mp[s[r]] = r;
        r++;
    }

    cout << "Max Len is: " << maxLen;
}

void maxConsecOnes()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];

        if (nums[i] == 0)
        {
            sum = 0;
        }

        maxi = max(sum, maxi);
    }

    cout << "Max one is: " << maxi;
}

void maxConsecOnesTwo()
{
    int maxi = 0;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    for (int i = 0; i < nums.size(); i++)
    {
        int zeroes = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                zeroes = zeroes + 1;
            }

            if (zeroes <= 2)
            {
                int len = j - i + 1;
                maxi = max(len, maxi);
            }
            else
            {
                break;
            }
        }
    }

    cout << "Max ones is: " << maxi;
}

void slideWindowConecOnes()
{
    int maxi = 0;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int l = 0;
    int r = 0;
    int zeroes = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
        {
            zeroes++;
        }

        if (zeroes > 2)
        {
            while (zeroes > 2)
            {
                if (nums[l] == 0)
                {
                    zeroes--;
                }
                l++;
            }
        }

        maxi = max(maxi, r - l + 1);
        r++;
    }
}

void sum()
{
    int arr[] = {2, 0, 0, 3, -1, -1};
    map<long long, int> mp;
    long long sum = 0;
    int maxi = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = -2;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum == k)
        {
            maxi = max(maxi, i + 1);
        }

        long long rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxi = max(maxi, len);
        }

        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    cout << "The longest subarray is: " << maxi;
}

vector<int> findDuplicates2(vector<int> &nums)
{
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                result.push_back(nums[i]);
                break;
            }
        }
    }

    return result;
}

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> result;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second >= 2)
        {
            result.push_back(i->first);
        }
    }

    return result;
}

int search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
            return mid;

        if (nums[s] <= nums[mid])
        {
            if (nums[mid] >= target && nums[s] <= target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        if (nums[mid] < nums[e])
        {
            if (nums[mid] <= target && nums[e] >= target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }

    return -1;
}

int findMin(vector<int> &nums)
{
    int mini = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        mini = min(nums[i], mini);
    }

    return mini;
}

vector<int> findDuplicates3(vector<int> &nums)
{
    int n = nums.size();

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int num = abs(nums[i]);

        if (nums[num - 1] < 0)
        {
            result.push_back(num);
            cout << num << " ";
        }
        else
        {
            nums[num - 1] *= -1;
        }
    }

    return result;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> result;

    int product = 1;
    bool zeroExist = false;
    int cntZero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zeroExist = true;
            cntZero++;
            continue;
        }
        product = product * nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (zeroExist && nums[i] == 0)
        {
            if (cntZero > 1)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(product);
            }
        }
        else
        {
            int isNegative = 1;
            if (nums[i] < 0)
            {
                isNegative *= -1;
            }
            int val = (product / abs(nums[i])) * isNegative;
            if (zeroExist)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(val);
            }
        }
    }

    return result;
}

void ThreeSumBetter()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    set<vector<int>> st;
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        unordered_map<int, int> mp;
        for (int j = i + 1; j < n; j++)
        {
            int val = -1 * (nums[i] + nums[j]);
            if (mp.find(val) != mp.end())
            {
                vector<int> temp = {nums[i], nums[j], val};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            else
            {
                mp.insert({nums[j], j});
            }
        }
    }
    ans.insert(ans.end(), st.begin(), st.end());

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}


void mostWaterBrute(){
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int maxi = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int diff = j - i;
            int mini = min(nums[i], nums[j]);
            maxi = max(maxi, (mini * diff));
        }
    }

    cout << "Maxi is: " << maxi;
}

int main()
{
    mostWaterBrute();
    return 0;
}