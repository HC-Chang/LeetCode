/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 1)
            return 0;
        sort(nums.begin(), nums.end());
        int val = 1;
        int tmp = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == 1)
                tmp++;
            else if (nums[i] == nums[i - 1])
                continue;
            else
            {
                val = max(val, tmp);
                tmp = 1;
            }
        }

        return max(tmp, val);
    }
};
// @lc code=end

// Hash Table or Union Find