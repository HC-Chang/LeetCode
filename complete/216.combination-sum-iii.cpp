/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int t, int &k, int &arr_index, vector<int> &arr,
             vector<vector<int>> &ans)
    {
        int d = k - arr_index;
        if (t < 0 || t > (i * 2 - d + 1) * d)
            return;
        if (arr_index == k)
        {
            ans.push_back(arr);
            return;
        }
        for (int j = i; j > d - 1; j--)
        {
            arr.push_back(j);
            dfs(j - 1, t - j, k, ++arr_index, arr, ans);
            arr.pop_back();
            --arr_index;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        int arr_index = 0;
        vector<int> arr;
        vector<vector<int>> ans;
        dfs(9, n, k, arr_index, arr, ans);
        return ans;
    }
};
// @lc code=end

// Note: backtracking