/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> prefix;
        prefix.push_back(arr[0]);
        int n = arr.size();
        for (int i = 1; i < n; i++)
            prefix.push_back(prefix[i - 1] ^ arr[i]);

        vector<int> ans;
        for (auto q : queries)
        {
            if (q[0] == q[1])
                ans.push_back(arr[q[0]]);
            else if (q[0] == 0)
                ans.push_back(prefix[q[1]]);
            else
                ans.push_back(prefix[q[1]] ^ prefix[q[0] - 1]);
        }
        return ans;
    }
};
// @lc code=end

// Note: bit manipulation + prefix sum