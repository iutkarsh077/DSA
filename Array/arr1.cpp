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

int main()
{
    subArrayZero();
    return 0;
}
