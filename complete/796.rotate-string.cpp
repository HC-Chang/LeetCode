/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return (s.size() == goal.size()) ? (s + s).find(goal) != string::npos : false;
    }
};
// @lc code=end

// Note: string matching