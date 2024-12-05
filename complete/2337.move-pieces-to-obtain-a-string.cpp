/*
 * @lc app=leetcode id=2337 lang=cpp
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
class Solution
{
public:
    bool canChange(string start, string target)
    {
        int n = start.size();
        int s_idx = 0, t_idx = 0;

        while (s_idx < n || t_idx < n)
        {
            while (s_idx < n && start[s_idx] == '_')
                s_idx++;

            while (t_idx < n && target[t_idx] == '_')
                t_idx++;

            if (s_idx == n || t_idx == n)
                return s_idx == n && t_idx == n;

            if (start[s_idx] != target[t_idx] ||
                (start[s_idx] == 'L' && s_idx < t_idx) ||
                (start[s_idx] == 'R' && s_idx > t_idx))
                return false;

            s_idx++;
            t_idx++;
        }

        return true;
    }
};
// @lc code=end

// Note: two pointers