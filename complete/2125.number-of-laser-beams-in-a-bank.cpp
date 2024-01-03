/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        int cnt = 0;
        int cur = 0;
        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            cur = 0;
            for (auto c : bank[i])
            {
                if (c == '1')
                    cur++;
            }
            if (pre == 0)
                pre = cur;
            else if (cur != 0)
            {
                cnt += pre * cur;
                pre = cur;
            }
        }

        return cnt;
    }
};
// @lc code=end
