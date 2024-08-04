/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> arr;

        int tmp;
        for (int i = 0; i < n; i++)
        {
            tmp = 0;
            for (int j = i; j < n; j++)
            {
                tmp += nums[j];
                arr.push_back(tmp);
            }
        }
        sort(arr.begin(), arr.end());

        long long ans = 0;
        for (int i = left - 1; i < right; i++)
            ans += arr[i];
        ans = ans % (1000000007);
        return (int)ans;
    }
};
// @lc code=end

// Note: sorting