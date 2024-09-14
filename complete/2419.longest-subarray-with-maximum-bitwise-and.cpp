/*
 * @lc app=leetcode id=2419 lang=c
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max_val = 0;
        int ans = 0;
        int cur = 0;

        for (auto n : nums)
        {
            if (max_val < n)
            {
                max_val = n;
                cur = 0;
                ans = cur;
            }

            if (max_val == n)
                cur++;
            else
                cur = 0;

            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

// Note: bit manipulation

// Official Solution