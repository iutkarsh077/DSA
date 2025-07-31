#include <iostream>
#include <vector>
#include <unordered_map>
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
    while(r < nums.size()){
        if(nums[r] == 0){
            zeroes++;
        }

        if(zeroes > 2){
            while(zeroes > 2){
                if(nums[l] == 0){
                    zeroes--;
                }
                l++;
            }
        }

        maxi = max(maxi, r - l + 1);
        r++;
    }
}

void sum(){
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
}

int main()
{
    maxConsecOnesTwo();
    return 0;
}