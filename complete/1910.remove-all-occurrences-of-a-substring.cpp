/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.find(part) != std::string::npos)
            s.erase(s.find(part), part.size());
        return s;
    }
};
// @lc code=end

// Note: stack + simulation