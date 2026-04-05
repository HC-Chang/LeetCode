/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int cnt[2] = {0};
        for (auto &c : moves)
        {
            switch (c)
            {
            case 'R':
                ++cnt[0];
                break;
            case 'L':
                --cnt[0];
                break;
            case 'U':
                ++cnt[1];
                break;
            case 'D':
                --cnt[1];
                break;
            }
        }

        return cnt[0] == 0 && cnt[1] == 0;
    }
};
// @lc code=end
