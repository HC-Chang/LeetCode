/*
 * @lc app=leetcode id=3731 lang=cpp
 *
 * [3731] Find Missing Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int tmp = nums[i - 1];
            while (nums[i] - tmp != 1)
                ans.push_back(++tmp);
        }
        return ans;
    }
};
// @lc code=end

// Note: sorting