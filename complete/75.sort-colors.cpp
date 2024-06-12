/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int hash[3] = {0};
        for (auto i : nums)
            ++hash[i];
        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < hash[i]; j++)
                nums[idx++] = i;
        }
    }
};
// @lc code=end

// Note: sorting