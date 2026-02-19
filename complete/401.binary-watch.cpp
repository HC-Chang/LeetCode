/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        if (turnedOn > 8)
            return {};

        vector<string> ans;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (turnedOn == __builtin_popcount(i) + __builtin_popcount(j))
                    ans.push_back(format("{}:{:0>2}", i, j));
            }
        }
        return ans;
    }
};
// @lc code=end

// Note: back tracking + bit manipulation