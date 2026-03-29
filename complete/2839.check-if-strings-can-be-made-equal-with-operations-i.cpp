/*
 * @lc app=leetcode id=2839 lang=cpp
 *
 * [2839] Check if Strings Can be Made Equal With Operations I
 */

// @lc code=start
class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        int n = s1.size();
        if (s2.size() != n)
            return false;

        vector<int> used(n);
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
                continue;
            else if (i + 2 < n && s1[i] == s2[i + 2])
                ++used[i];
            else if (i - 2 >= 0 && s1[i] == s2[i - 2])
                --used[i - 2];
            else
                return false;
        }

        for (auto &u : used)
        {
            if (u != 0)
                return false;
        }

        return true;
    }
};
// @lc code=end

// Note: string