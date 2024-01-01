/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int g_index = 0;
        int s_index = 0;
        int gSize = g.size();
        int sSize = s.size();
        while (g_index < gSize && s_index < sSize)
        {
            if (g[g_index] <= s[s_index])
            {
                count++;
                g_index++;
                s_index++;
            }
            else
                s_index++;
        }
        return count;
    }
};
// @lc code=end
