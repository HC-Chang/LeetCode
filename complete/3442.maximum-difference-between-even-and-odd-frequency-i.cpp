/*
 * @lc app=leetcode id=3442 lang=cpp
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
class Solution
{
public:
    int maxDifference(string s)
    {
        unordered_map<char, int> hash;
        for (auto c : s)
            ++hash[c];

        vector<int> maxs(2, INT_MIN);
        vector<int> mins(2, INT_MAX);

        for (auto h : hash)
        {
            if (h.second > maxs[h.second % 2])
                maxs[h.second % 2] = h.second;
            if (h.second < mins[h.second % 2])
                mins[h.second % 2] = h.second;
        }

        return max(mins[1] - maxs[0], maxs[1] - mins[0]);
    }
};
// @lc code=end

// Note: hash table