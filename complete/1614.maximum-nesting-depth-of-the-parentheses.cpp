/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution
{
public:
    int maxDepth(string s)
    {
        int max_cnt = 0;
        int cnt = 0;

        for (auto c : s)
        {
            switch (c)
            {
            case '(':
                if (++cnt > max_cnt)
                    max_cnt = cnt;
                break;
            case ')':
                cnt--;
                break;
            }
        }
        return max_cnt;
    }
};
// @lc code=end

// Note: stack