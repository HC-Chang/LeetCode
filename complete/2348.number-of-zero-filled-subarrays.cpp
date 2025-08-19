/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long total_cnt = 0;
        int n = nums.size();
        long long j;
        for (long long i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                continue;
            j = i;
            while (j + 1 < n && nums[j + 1] == 0)
                j++;
            total_cnt += (2 + j - i) * (j - i + 1) / 2;
            i = j;
        }

        return total_cnt;
    }
};
// @lc code=end

// Note: math