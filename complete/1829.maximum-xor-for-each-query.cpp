/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        int xor_product = 0;
        for (int i = 0; i < n; i++)
            xor_product = xor_product ^ nums[i];

        vector<int> ans(n);

        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < n; i++)
        {
            ans[i] = xor_product ^ mask;
            xor_product = xor_product ^ nums[n - 1 - i];
        }

        return ans;
    }
};
// @lc code=end

// Note: bit manipulation + prefix sum

// Official Solution