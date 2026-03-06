/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int flag = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (flag == 1)
                    return false;
                flag = 1;
                while (i + 1 < n && s[i + 1] == '1')
                    i++;
            }
        }

        return true;
    }
};
// @lc code=end
