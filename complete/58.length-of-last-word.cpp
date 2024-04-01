/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;

        int cnt = 0;
        if (s[0] != ' ')
            cnt = 1;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i] != ' ')
            {
                if (s[i - 1] == ' ')
                    cnt = 1;
                else
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
