/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int min_val = nums[k];
        int r = min_val;
        int i = k;
        int j = k;
        while (i > 0 || j < nums.size() - 1)
        {
            if (i == 0 || (j + 1 < nums.size() && nums[i - 1] <= nums[j + 1]))
            {
                j++;
                min_val = min(min_val, nums[j]);
                r = max(r, min_val * (j - i + 1));
            }
            else
            {
                i--;
                min_val = min(min_val, nums[i]);
                r = max(r, min_val * (j - i + 1));
            }
        }
        return r;
    }
};
// @lc code=end
