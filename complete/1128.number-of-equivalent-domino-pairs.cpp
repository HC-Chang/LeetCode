/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        vector<int> arr(100);
        int ret = 0;
        for (auto &d : dominoes)
        {
            int val = d[0] < d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            ret += arr[val];
            arr[val]++;
        }
        return ret;
    }
};

// @lc code=end

// Note: hash table