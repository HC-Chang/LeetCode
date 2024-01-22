/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> hash(n + 1);
        for (auto i : nums)
            ++hash[i];
        vector<int> ans(2);
        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 2)
                ans[0] = i;
            else if (hash[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
};
// @lc code=end

// Note: hash map
