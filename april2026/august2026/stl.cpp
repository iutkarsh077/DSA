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

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int pre = 1;
    int suf = 1;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;

        pre = pre * nums[i];
        suf = suf * nums[n - i - 1];
        maxi = max(maxi, max(pre, suf));
    }

    return maxi;
}

int lowerBound(vector<int> &arr, int target)
{
    int index = arr.size();

    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] >= target)
        {
            index = min(mid, index);
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return index;
}

int searchInsert(vector<int> &arr, int target)
{
    int index = arr.size();

    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
        {
            index = min(mid, index);
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return index;
}

vector<int> searchRange(vector<int> &arr, int target)
{
    int lowerBound = -1;

    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            lowerBound = mid;
            end = mid - 1;
        }

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    if (lowerBound == -1)
    {
        return {-1, -1};
    }

    int upperBound = lowerBound;
    start = lowerBound + 1;
    end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            upperBound = mid;
            start = mid + 1;
        }

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return {lowerBound, upperBound};
}

int countFreq(vector<int> &arr, int target)
{
    int startIndex = INT_MAX;
    int endIndex = INT_MIN;

    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            startIndex = min(mid, startIndex);
            end = mid - 1;
        }

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    if (startIndex == INT_MAX)
    {
        return 0;
    }

    start = startIndex - 1;
    end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            endIndex = max(mid, endIndex);
            start = mid + 1;
        }

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    int series = (endIndex - startIndex) + 1;

    return series;
}

int search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[s] <= nums[mid])
        {

            if (nums[s] <= target && target < nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        else
        {

            if (nums[mid] < target && target <= nums[e])
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

int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1 || nums[0] != nums[1])
        return nums[0];
    int n = nums.size();
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int s = 1;
    int e = n - 2;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        else if (mid % 2 != 0)
        {
            if (nums[mid] == nums[mid + 1])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    return -1;
}

long long checker(vector<int> arr, int mid)
{
    long long total = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans1 = (arr[i] + (long long)mid - 1) / mid;
        total += ans1;
    }

    return total;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = 0;

    for (int i = 0; i < piles.size(); i++)
    {
        maxi = max(maxi, piles[i]);
    }

    int s = 1;
    int e = maxi;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        long long ans = checker(piles, mid);

        if (ans <= h)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return s;
}

string reverseWords(string s)
{
    int i = 0;
    string ans = "";

    while (i < s.size())
    {
        string val = "";

        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        while (i < s.size() && s[i] != ' ')
        {
            val += s[i];
            i++;
        }

        if (!val.empty())
        {
            ans = val + ' ' + ans;
        }
    }

    ans.pop_back();

    return ans;
}

string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            if (i + k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }


string largestOddNumber(string num) {
        int n = num.size();
        int i = n - 1;

        while(i >= 0){
            int val = num[i] - '0';

            if(val % 2 != 0){
                string ans = num.substr(0, i + 1);
                return ans;
            }
            i--;
        }

        return "";
}

string removeOuterParentheses(string s)
{
    string result = "";

    int counter = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (counter > 0)
            {
                result += s[i];
            }

            counter++;
        }

        else if (s[i] == ')')
        {
            counter--;

            if (counter > 0)
            {
                result += s[i];
            }
        }
    }

    return result;
}

int checker(vector<int> arr, int mid, int days)
{
    int cnt = 1;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] > mid)
        {
            cnt++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }

    return cnt;
}

int shipWithinDays(vector<int> &arr, int days)
{
    int maxi = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        maxi = maxi + arr[i];
    }

    int ans = INT_MAX;
    int s = 1;
    int e = maxi;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        int count = checker(arr, mid, days);

        if (count <= days)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int findKthPositive(vector<int> &arr, int k)
{
    int cnt = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 1; i <= 2000; i++)
    {
        if (mp.find(i) != mp.end())
        {
            continue;
        }
        cnt++;
        if (cnt == k)
        {
            return i;
        }
    }

    return -1;
}

int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1 || nums[0] > nums[1])
        return 0;
    int n = nums.size();
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int maxi = INT_MIN;

    for (int i = n - 2; i >= 1; i--)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            return i;
        }
    }

    return -1;
}

int binarysearch(vector<int> &nums, int target)
{
    int start = 0;
    int n = nums.size();
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int Merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    vector<int> temp;

    while (left <= mid && right <= high)
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
            cnt += (mid - left + 1);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int DivideIt(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += DivideIt(arr, low, mid);
    cnt += DivideIt(arr, mid + 1, high);
    cnt += Merge(arr, low, mid, high);

    return cnt;
}
int inversionCount(vector<int> &arr)
{
    int cnt = DivideIt(arr, 0, arr.size() - 1);
    return cnt;
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

vector<int> rearrangeArray(vector<int> &nums)
{
    int pos = 0;
    int neg = 1;
    int n = nums.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            ans[pos] = nums[i];
            pos = pos + 2;
        }
        else
        {
            ans[neg] = nums[i];
            neg = neg + 2;
        }
    }

    return ans;
}

vector<int> BiggerOne(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    ans.push_back(arr[n - 1]);
    int maxi = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxi)
        {
            maxi = arr[i];
            ans.push_back(maxi);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int longestConsecutive(vector<int> &nums)
{

    if (nums.size() == 0)
        return 0;
    int maxi = 1;
    sort(nums.begin(), nums.end());
    int cnt = 1;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            continue;
        }
        else if (nums[i] + 1 != nums[i + 1])
        {
            maxi = max(cnt, maxi);
            cnt = 1;
        }

        else
        {
            cnt++;
        }
    }

    maxi = max(cnt, maxi);

    return maxi;
}

void setZeroes(vector<vector<int>> &matrix)
{
    vector<int> rows(matrix.size(), -1);
    vector<int> cols(matrix[0].size(), -1);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (rows[i] == 0 || cols[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {

        for (int j = left; j <= right; j++)
        {
            ans.push_back(matrix[top][j]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                temp.push_back(1);
            }
            else
            {
                int value = ans[i - 1][j - 1] + ans[i - 1][j];
                temp.push_back(value);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int need = nums[i] + nums[j];
            need = need * -1;

            if (hashset.find(need) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], need};
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> result(ans.begin(), ans.end());
    return result;
}

void LinearSearch()
{
    int target = 5;
    vector<int> ans = {1, 5, 4, 2, 37, 8, 5};
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == target)
        {
            cout << "Index for target is: " << i << endl;
        }
    }
}

void rotateSecond(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotateThird(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotateFourth(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

vector<int> majorityElement22(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second > nums.size() / 3)
        {
            ans.push_back(i->first);
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

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    // O(nlogn) + O(n ^ 2)

    int closed = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closed - target))
            {
                closed = sum;
            }

            if (sum > target)
            {
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                // equal too
                return sum;
            }
        }
    }

    return closed;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

void rotate(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
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

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int closed = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closed - target))
            {
                closed = sum;
            }

            if (sum > target)
            {
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                // equal too
                return sum;
            }
        }
    }

    return closed;
}

int main()
{
    vector<int> arr = {5, 6, 2, 1, 9, 8, 6, 4};
    Quicksort(arr, 0, arr.size() - 1);
    printMe(arr);
    return 0;
}
