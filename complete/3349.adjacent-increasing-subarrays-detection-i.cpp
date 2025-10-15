/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
class Solution
{
public:
    bool find_k(int idx, int k, vector<int> &nums)
    {
        for (int i = 1; i < k; i++)
        {
            if (nums[idx + i] <= nums[idx + i - 1])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 1)
            return true;
        int offset;
        bool b1, b2;
        for (int i = 0; i <= n - 2 * k; i++)
        {
            offset = 0;
            b1 = find_k(i, k, nums);
            b2 = find_k(i + k, k, nums);
            if (b1 && b2)
                return true;
            if (b1)
                offset += k;
            if (b2)
                offset += k;
        }
        return false;
    }
};
// @lc code=end
