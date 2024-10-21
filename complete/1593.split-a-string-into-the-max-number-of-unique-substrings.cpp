/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
class Solution
{
public:
    void backtrack(const string &s, int start, unordered_set<string> &seen,
                   int count, int &maxCount)
    {
        if (count + (s.size() - start) <= maxCount)
            return;

        if (start == s.size())
        {
            maxCount = max(maxCount, count);
            return;
        }

        for (int end = start + 1; end <= s.size(); ++end)
        {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end())
            {
                seen.insert(substring);
                backtrack(s, end, seen, count + 1, maxCount);
                seen.erase(substring);
            }
        }
    }

    int maxUniqueSplit(string s)
    {
        unordered_set<string> seen;
        int maxCount = 0;
        backtrack(s, 0, seen, 0, maxCount);
        return maxCount;
    }
};
// @lc code=end

// Note: hash table + backtracking

// Official Solution