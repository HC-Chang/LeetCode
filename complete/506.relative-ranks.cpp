/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<int> idx(n);
        vector<string> ans(n, "");
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        sort(idx.begin(), idx.end(),
             [&](int a, int b)
             { return score[a] > score[b]; });
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
                ans[idx[i]] = "Gold Medal";
            else if (i == 1)
                ans[idx[i]] = "Silver Medal";
            else if (i == 2)
                ans[idx[i]] = "Bronze Medal";
            else
                ans[idx[i]] = to_string(i + 1);
        }
        return ans;
    }
};
// @lc code=end

// Note: sorting + min heap