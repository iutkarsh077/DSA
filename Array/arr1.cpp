#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void largestElement()
{
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }

    cout << "Largest element is: " << maxi;
}

void secondLargestElement()
{
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int maxi = INT_MIN;
    int maxiIndex = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= maxi)
        {
            maxi = nums[i];
            maxiIndex = i;
        }
    }

    nums[maxiIndex] = INT_MIN;
    int secMaxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        secMaxi = max(secMaxi, nums[i]);
    }

    cout << "second largest element is: " << secMaxi;
}

bool check(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;

    int cnt = 0;
    if (nums[0] < nums[n - 1])
        cnt++;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
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

void rotaeByOnePlace()
{
    vector<int> nums;
    nums = {1, 2, 3, 4, 5};

    int first = nums[0];
    if (nums.size() == 1)
        return;

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i - 1] = nums[i];
    }

    nums[nums.size() - 1] = first;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void moveZeroes()
{
    vector<int> nums = {0};

    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void LinearSearch()
{
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int target = 5;

    for (int i = 0; i < nums.size(); i++)
    {
        if (target == nums[i])
        {
            cout << i;
            break;
        }
    }
}

void FindTheUnion()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < arr1.size())
    {
        if (ans.size() >= 1 && ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < arr2.size())
    {
        if (ans.size() >= 1 && ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int singleNumber(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    sort(nums.begin(), nums.end());

    if (nums[0] != nums[1])
        return nums[0];

    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }

    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        return nums[nums.size() - 1];
    }

    return -1;
}

void sumKPositives()
{
    vector<int> nums = {2, 3, 5};
    int k = 5;
    unordered_map<int, int> mp;
    int maxi = 0;
    mp.insert({0, -1});
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
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
    cout << "The answer is: " << maxi;
}

void sumK()
{
    vector<int> nums = {2, 3, 5, 1, 9};
    int k = 10;

    int left = 0;
    int right = 0;
    int maxi = 0;
    int sum = 0;
    while (right < nums.size())
    {
        sum = sum + nums[right];

        while (left <= right && sum > k)
        {
            sum = sum - nums[left];
            left++;
        }

        if (sum == k)
        {
            maxi = max(maxi, right - left + 1);
        }

        right++;
    }

    cout << "The answer is: " << maxi;
}

void sortColors()
{
    vector<int> nums = {2, 0, 1};

    int zeroes = 0;
    int ones = 0;
    int two = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zeroes++;
        }
        else if (nums[i] == 1)
        {
            ones++;
        }
        else
        {
            two++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (zeroes > 0)
        {
            nums[i] = 0;
            zeroes--;
        }

        else if (ones > 0)
        {
            nums[i] = 1;
            ones--;
        }

        else
        {
            nums[i] = 2;
            two--;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
}

void KadaneAlgo()
{
    vector<int> nums = {1};

    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];

        maxi = max(maxi, sum);

        if (sum <= 0)
        {
            sum = 0;
        }
    }

    cout << "The maxi is: " << maxi;
}

int maxProfit(vector<int> &prices)
{
    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for (int i = 0; i < prices.size(); i++)
    {
        minValue = min(prices[i], minValue);
        maxValue = max(maxValue, prices[i] - minValue);
    }

    return maxValue;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> dupNums(nums.size(), 0);
    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            dupNums[posIndex] = nums[i];
            posIndex = posIndex + 2;
        }
        else
        {
            dupNums[negIndex] = nums[i];
            negIndex = negIndex + 2;
        }
    }

    copy(dupNums.begin(), dupNums.end(), nums.begin());
    return nums;
}

int longestConsecutive()
{
    vector<int> nums = {1, 0, 1, 2};
    if (nums.size() == 0)
        return 0;

    int maxCnt = 0;
    int n = nums.size();
    int cnt = 1;
    set<int> st;

    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    for (auto i = st.begin(); i != st.end(); i++)
    {
        int needVal = (*i) + 1;
        auto it = st.find(needVal);

        if (it != st.end())
        {
            cnt++;
        }
        else
        {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
        }
    }

    maxCnt = max(maxCnt, cnt);

    cout << maxCnt;

    return maxCnt;
}

void setZeroes()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> rows(m, 1);
    vector<int> column(n, 1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 0;
                column[j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rows[i] == 0 || column[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
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

    return;
}

int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;
    int sum = 0;
    unordered_map<int, int> mp;

    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        int need = sum - k;
        cnt += mp[need];
        mp[sum] += 1;
    }

    return cnt;
}

void generate()
{
    int numRows = 5;
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp(i + 1, 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                continue;
            }

            int val = ans[i - 1][j - 1] + ans[i - 1][j];
            temp[j] = val;
        }
        ans.push_back(temp);
    }

    int n = ans.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> majorityElement2(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        int val = i->second;
        int val2 = i->first;
        if (val > n / 3)
        {
            ans.push_back(val2);
        }
    }

    return ans;
}

void sprialMatrix()
{
    vector<vector<int>> nums = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30}};

    int row = nums.size();
    int column = nums[0].size();
    int left = 0;
    int right = column - 1;
    int top = 0;
    int bottom = row - 1;
    vector<int> ans;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(nums[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(nums[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(nums[i][left]);
            }
            left++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                ans.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }

            else if (sum > 0)
            {
                right--;
            }

            else
            {
                left++;
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}

void subArrayZero()
{
    vector<int> nums = {6, -2, 2, -8, 1, 7, 4, -10};
    unordered_map<int, int> mp;
    int maxi = 0;
    int sum = 0;
    mp.insert({0, -1});
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        int need = -1 * sum;
        if (mp.find(need) != mp.end())
        {
            int index = mp[need];
            maxi = max(maxi, index - i);
        }
        mp[sum] = i;
    }

    cout << "Maximum subarray is: " << maxi;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = 0;
    int right = 0;
    vector<int> ans;

    while (left < m && right < n)
    {
        if (nums1[left] <= nums2[right])
        {
            ans.push_back(nums1[left]);
            left++;
        }
        else
        {
            ans.push_back(nums2[right]);
            right++;
        }
    }

    while (left < m)
    {
        ans.push_back(nums1[left]);
        left++;
    }

    while (right < n)
    {
        ans.push_back(nums2[right]);
        right++;
    }

    nums1.clear();
    for (int i = 0; i < ans.size(); i++)
    {
        nums1.push_back(ans[i]);
    }
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    vector<int> ans;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            ans.push_back(grid[i][j]);
        }
    }

    sort(ans.begin(), ans.end());
    int repeated = -1;

    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] == ans[i + 1])
        {
            repeated = ans[i];
            break;
        }
    }

    int length = ans.size();
    int total = (length * (length + 1)) / 2;
    int ansSum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        ansSum += ans[i];
    }

    ansSum = ansSum - repeated;

    int val = total - ansSum;

    return {repeated, val};
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

        else if (nums[mid] > target)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int findFloor(int *arr, int n, int x)
{
    int s = 0;
    int e = n - 1;
    int result = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] <= x)
        {
            result = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return result;
}

int findCeil(vector<int> &arr, int x)
{
    // code here
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int result = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] >= x)
        {
            result = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return result;
}

int lowerBound(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    int indexAns = n;
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] >= target)
        {
            e = mid - 1;
            indexAns = mid;
        }
        else
        {
            s = mid + 1;
        }
    }

    return indexAns;
}

int search2(vector<int> &nums, int target)
{
    int n = nums.size();

    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return mid;
        }

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

int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = INT_MIN;
    int n = piles.size();

    for (int i = 0; i < n; i++)
    {
        maxi = max(piles[i], maxi);
    }

    int s = 1;
    int e = maxi;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        double hour = 0;

        for (int i = 0; i < n; i++)
        {
            double val = ceil((double)piles[i] / mid);
            hour += val;
        }

        if (hour <= h)
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

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int index = 0;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[mid] < target)
        {
            index = mid + 1;
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    return index;
}

bool search3(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return true;
        }

        if (nums[s] == nums[mid] && nums[mid] == nums[e])
        {
            s++;
            e--;
            continue;
        }

        if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && nums[mid] >= target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        if (nums[mid] <= nums[e])
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

    return false;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int ans1 = -1;
    int ans2 = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            ans1 = mid;
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    s = 0;
    e = n - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            ans2 = mid;
            s = mid + 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return {ans1, ans2};
}

void findMin()
{
    vector<int> nums = {4, 5, 6, 7, 8, 1, 2};

    int s = 0;
    int e = nums.size() - 1;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (nums[s] <= nums[mid])
        {
            ans = min(ans, nums[s]);
            s = mid + 1;
        }

        if (nums[mid] <= nums[e])
        {
            ans = min(nums[mid], ans);
            e = mid - 1;
        }
    }

    cout << "Minimum ans is: " << ans;
}

void minDays()
{
    vector<int> nums = {1, 10, 3, 10, 2};

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int k = 1;
    int m = 3;

    for (int x : nums)
    {
        minVal = min(minVal, x);
        maxVal = max(maxVal, x);
    }

    int s = minVal, e = maxVal;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int cnt = 0, flowerCnt = 0;

        for (int x : nums)
        {
            if (x <= mid)
            {
                cnt++;
                if (cnt == k)
                {
                    flowerCnt++;
                    cnt = 0;
                }
            }
            else
            {
                cnt = 0;
            }
        }

        if (flowerCnt >= m)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << "Minimum days is: " << ans;
}

void findMin2()
{
    vector<int> nums = {3, 4, 5, -2, 1, 2, 3};
    int s = 0;
    int e = nums.size() - 1;
    int mini = INT_MAX;
    int minIndex = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[s] <= nums[mid])
        {
            if (nums[s] < mini)
            {
                mini = nums[s];
                minIndex = s;
            }
            s = mid + 1;
        }

        if (nums[mid] <= nums[e])
        {
            if (nums[mid] < mini)
            {
                mini = nums[mid];
                minIndex = mid;
            }
            e = mid - 1;
        }
    }

    cout << "The minimum number of when array is rotated: " << minIndex << " " << mini;
}

void sqrt()
{
    int x = 0;
    int ans = 0;
    int s = 1;
    int e = x / 2;
    if (x == 1)
        return;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        long long val = static_cast<long long>(mid) * mid;

        if (val <= x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << "The sqrt is: " << ans;
}

void minDays2()
{
    vector<int> nums = {7, 7, 7, 7, 12, 7, 7};
    int m = 2;
    int k = 3;
    int n = nums.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
    }

    int s = mini;
    int e = maxi;
    int minDay = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        int cnt = 0;
        int bouquetCnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                cnt++;
                if (cnt == k)
                {
                    bouquetCnt++;
                    cnt = 0;
                }
            }

            else
            {
                cnt = 0;
            }
        }

        if (bouquetCnt >= m)
        {
            minDay = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << "Min days is: " << minDay;
}

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }

    int s = 1;
    int e = n - 2;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        else if (nums[mid] == nums[mid - 1])
        {
            if (mid % 2 == 1)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        else if (nums[mid] == nums[mid + 1])
        {
            if (mid % 2 == 1)
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

void smallestdivisor()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    int maxi = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
    }

    int s = 1;
    int e = maxi;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int divison = ceil((double)nums[i] / mid);
            sum += divison;
        }

        if (sum <= threshold)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << ans;
}

int findKthPositive(vector<int> &nums, int k)
{
    int missing = 0;
    int val = 1;
    int i = 0;

    while (missing < k && i < nums.size())
    {
        if (val != nums[i])
        {
            missing++;
            if (missing == k)
                return val;
            val++;
        }

        if (val == nums[i])
        {
            val++;
            i++;
        }
    }

    if (missing == k)
        return val;

    while (missing < k)
    {
        missing++;
        if (missing == k)
            return val;
        val++;
    }

    return val;
}

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int maxi = -1;
    int index = -1;
    int row = mat.size();
    int column = mat[0].size();

    for (int i = 0; i < row; i++)
    {
        int cnt = 0;
        for (int j = 0; j < column; j++)
        {
            if (mat[i][j] == 1)
            {
                cnt++;
            }
        }

        if (cnt > maxi)
        {
            maxi = max(maxi, cnt);
            index = i;
        }
    }

    return {index, maxi};
}

void removeOuterParentheses()
{
    string s = "(()())(())(()(()))";
    string ans = "";
    int cnt = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            cnt++;

        if (s[i] == ')')
            cnt--;

        if (s[i] == '(' && cnt >= 1)
            ans += s[i];

        if (s[i] == ')' && cnt >= 0)
            ans += s[i];
    }

    cout << ans;
}

string reverseWords(string s)
{
    int i = 0;
    int n = s.size();
    string result = "";
    while (i < n)
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }

        string ans = "";
        while (s[i] != ' ' && i < n)
        {
            ans += s[i];
            i++;
        }

        result = ans + ' ' + result;
    }

    result.pop_back();

    return result;
}

int main()
{
    removeOuterParentheses();
    return 0;
}
