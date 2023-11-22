/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.first + x.second != y.first + y.second)
    {
        return x.first + x.second < y.first + y.second;
    }
    return x.first > y.first;
}

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> ans;
        vector<pair<int, int>> idx;
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
                idx.push_back({i, j});
        }
        sort(idx.begin(), idx.end(), cmp);
        for (int i = 0; i < idx.size(); i++)
            ans.push_back(nums[idx[i].first][idx[i].second]);

        return ans;
    }
};
// @lc code=end
