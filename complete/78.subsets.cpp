/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> arr;
        vector<int> element;
        int n = nums.size();
        function<void(int)> dfs = [&](int i)
        {
            if (i == n)
            {
                arr.emplace_back(element);
                return;
            }
            dfs(i + 1);
            element.push_back(nums[i]);
            dfs(i + 1);
            element.pop_back();
        };
        dfs(0);
        return arr;
    }
};
// @lc code=end

// Note: backtracking