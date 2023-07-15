/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> arr;
        vector<int> element;
        function<void(int)> dfs = [&](int i)
        {
            if (element.size() == k)
            {
                arr.emplace_back(element);
                return;
            }
            for (int j = i; j >= k - element.size(); j--)
            {
                element.push_back(j);
                dfs(j - 1);
                element.pop_back();
            }
        };
        dfs(n);
        return arr;
    }
};
// @lc code=end

// Note: backtracking