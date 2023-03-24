/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<vector<int>> &arr, vector<bool> &visited, int from)
    {
        auto ret = 0;
        visited[from] = true;
        for (auto to : arr[from])
            if (!visited[abs(to)])
                ret += dfs(arr, visited, abs(to)) + (to > 0);
        return ret;
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> arr(n);
        for (auto &connect : connections)
        {
            arr[connect[0]].push_back(connect[1]);
            arr[connect[1]].push_back(-connect[0]);
        }
        return dfs(arr, vector<bool>(n) = {}, 0);
    }
};
// @lc code=end
