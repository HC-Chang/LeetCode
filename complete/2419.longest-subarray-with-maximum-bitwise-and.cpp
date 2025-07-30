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
        int max_cnt = 0;
        int cnt = 0;

        for (auto n : nums)
        {
            if (max_val < n)
            {
                max_val = n;
                cnt = 0;
                max_cnt = cnt;
            }

            if (max_val == n)
            {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            }
            else
                cnt = 0;
        }
        return max_cnt;
    }
};
// @lc code=end

// Note: bit manipulation

// Official Solution