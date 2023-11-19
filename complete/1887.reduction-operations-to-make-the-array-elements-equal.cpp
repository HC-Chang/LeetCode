/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        vector<int> counts(50001, 0);
        for (int i = 0; i < nums.size(); i++)
            ++counts[nums[i]];

        int count = 0;
        int r = 0;
        for (int i = 50000; i >= 1; i--)
        {
            if (counts[i] > 0)
            {
                count += counts[i];
                r += count - counts[i];
            }
        }
        return r;
    }
};
// @lc code=end
