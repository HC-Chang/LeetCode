/*
 * @lc app=leetcode id=2138 lang=cpp
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> ans;
        while (s.size() % k)
            s += fill;
        int n = s.size();
        for (int i = 0; i < n; i += k)
            ans.push_back(s.substr(i, k));
        return ans;
    }
};
// @lc code=end

// Note: simulation