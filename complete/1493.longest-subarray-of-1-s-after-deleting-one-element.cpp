/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int max_len = 0;
        int cnt = 0;
        int last_cnt = 0;
        int z_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                cnt++;
            else
            {
                z_cnt++;
                max_len = max(max_len, last_cnt + cnt);
                last_cnt = cnt;
                cnt = 0;
            }
        }
        max_len = max(max_len, last_cnt + cnt);
        if (z_cnt == 0)
            max_len--;
        return max_len;
    }
};
// @lc code=end

// Note: sliding window