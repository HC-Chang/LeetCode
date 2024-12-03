/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int n = s.size();
        int nn = spaces.size();
        string ans;
        int idx = 0;
        int s_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s_idx < nn && i == spaces[s_idx])
            {
                ans += ' ';
                s_idx++;
            }
            ans += s[i];
        }

        return ans;
    }
};
// @lc code=end

// Note: two pointers