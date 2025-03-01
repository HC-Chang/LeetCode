/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        vector<int> ans(n);
        int idx = 0;
        for (auto nn : nums)
        {
            if (nn != 0)
                ans[idx++] = nn;
        }

        return ans;
    }
};
// @lc code=end

// Note: two pointers