/*
 * @lc app=leetcode id=3101 lang=cpp
 *
 * [3101] Count Alternating Subarrays
 */

// @lc code=start
class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long cnt = 1;
        int tmp_cnt = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                tmp_cnt = 0;
            tmp_cnt++;
            cnt += tmp_cnt;
        }

        return cnt;
    }
};
// @lc code=end

// Note: math
