#include <bits/stdc++.h>
using namespace std;

void pairme()
{
    pair<int, pair<int, int>> p = {1, {2, 3}};

    cout << p.second.second;
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second > p2.second)
        return false;
    if (p1.second < p2.second)
        return true;

    if (p1.first > p2.first)
        return true;
    return false;
}

void myset()
{
    set<int, greater<int>> s1 = {4, 1, 3, 2, 5, 6};
    s1.insert(20);
    s1.erase(1);

    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *(i) << " ";
    }

    cout << endl;
    cout << s1.size() << endl;

    auto it = s1.find(90);

    cout << *it;

    pair<int, int> mp[] = {{2, 3}, {4, 5}, {3, 2}};

    sort(mp, mp + 3, comp);
}

void iter()
{
    vector<int> v = {10, 20, 30, 40};

    v.insert(v.begin(), {1, 2, 3});

    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }
}

void MergeArray(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void printMe(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void DivideMe(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    DivideMe(arr, start, mid);
    DivideMe(arr, mid + 1, end);
    MergeArray(arr, start, mid, end);
}

int partition(vector<int> &arr, int low, int high)
{
    int left = low;
    int right = high;

    int cnt = 0;
    int i = low;
    while (i <= high)
    {
        if (arr[low] >= arr[i])
        {
            cnt++;
        }
        i++;
    }

    int partitionIndex = cnt + low - 1;

    swap(arr[partitionIndex], arr[low]);

    while (left < partitionIndex && right > partitionIndex)
    {
        while (arr[left] <= arr[partitionIndex])
        {
            left++;
        }

        while (arr[right] > arr[partitionIndex])
        {
            right--;
        }

        if (left < partitionIndex && right > partitionIndex)
        {
            swap(arr[left++], arr[right--]);
        }
    }

    return partitionIndex;
}

int largest(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;
    int maxi = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int getSecondLargest(vector<int> &arr)
{
    int maxi = arr[0];
    int maxiIndex = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
            maxiIndex = i;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == maxi)
        {
            arr[i] = -111;
        }
    }

    maxi = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

bool check(vector<int> &arr)
{
    int cnt = 0;

    if (arr[0] < arr[arr.size() - 1])
        cnt++;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cnt++;
        }
    }

    if (cnt <= 1)
        return true;

    return false;
}

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());
}

int removeDuplicates(vector<int> &nums)
{
    int i = 0;

    while (i < nums.size() - 1)
    {
        if (nums[i] == nums[i + 1])
        {
            nums.erase(nums.begin() + i, nums.begin() + i + 1);
        }
        else
        {
            i++;
        }
    }

    return nums.size();
}

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    set<int> st;

    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        st.insert(b[i]);
    }

    vector<int> result;

    for (auto i = st.begin(); i != st.end(); i++)
    {
        result.push_back(*i);
    }

    return result;
}

int missingNum(vector<int> &arr)
{

    long long sum = 0;
    for (long long i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
    }

    long long n = arr.size() + 1;
    long long totalSum = (n * (n + 1)) / 2;

    long long remaining = totalSum - sum;

    return remaining;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int cnt = 0;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            maxi = max(cnt, maxi);
            cnt = 0;
        }
        i++;
    }

    maxi = max(cnt, maxi);

    return maxi;
}

int longestSubarray(vector<int> &arr, int k)
{

    unordered_map<int, int> mp;
    mp[0] = -1;
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        int need = sum - k;

        if (mp.find(need) != mp.end())
        {
            maxi = max(maxi, i - mp[need]);
        }

        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return maxi;
}

vector<int> targetArea(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];

        if (mp.find(need) != mp.end())
        {
            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {-1, -1};
}

int majorityElement(vector<int> &nums)
{
    int val = nums[0];
    int cnt = 1;
    int maxi = 0;
    int realVal = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            if (cnt > maxi)
            {
                realVal = val;
            }
            maxi = max(maxi, cnt);
            cnt = 1;
            val = nums[i];
        }

        else
        {
            cnt++;
        }
    }

    maxi = max(cnt, maxi);

    return realVal;
}

int ProfitMaximum(vector<int> &prices)
{
    int maxiProfit = 0;
    int minPurchase = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        minPurchase = min(minPurchase, prices[i]);
        maxiProfit = max(maxiProfit, prices[i] - minPurchase);
    }

    return maxiProfit;
}

vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] >= 0){
                ans[pos] = nums[i];
                pos = pos + 2;
            }
            else{
                ans[neg] = nums[i];
                neg = neg + 2;
            }
        }

        return ans;
    }

void moveZeroes(vector<int> &nums)
{
    int cnt = 0;
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == 0)
        {
            cnt++;
            nums.erase(nums.begin() + i, nums.begin() + i + 1);
        }

        else
        {
            i++;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        nums.push_back(0);
    }
}
void Quicksort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int p = partition(arr, low, high);

    Quicksort(arr, low, p - 1);
    Quicksort(arr, p + 1, high);
}

int main()
{
    vector<int> arr = {5, 6, 2, 1, 9, 8, 6, 4};
    Quicksort(arr, 0, arr.size() - 1);
    printMe(arr);
    return 0;
}
