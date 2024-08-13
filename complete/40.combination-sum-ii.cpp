/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        dfs(result, combination, candidates, target, 0);
        return result;
    }
    void dfs(vector<vector<int>> &res, vector<int> &combination,
             vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i];
             ++i)
        {
            if (i == index || candidates[i] != candidates[i - 1])
            {
                combination.push_back(candidates[i]);
                dfs(res, combination, candidates,
                    target - candidates[i], i + 1);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end

// Note: backtracking

// Official Solution