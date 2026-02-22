/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution
{
public:
    int binaryGap(int n)
    {
        int cnt = 0;
        int tmp = 0;
        int flag = 0;
        while (n > 0)
        {
            if ((n & 1) == 0)
            {
                if (flag)
                    tmp++;
            }
            else
            {
                if (flag && tmp >= cnt)
                    cnt = ++tmp;
                flag = 1;
                tmp = 0;
            }
            n >>= 1;
        }
        return cnt;
    }
};
// @lc code=end

// NOTE: bit manipulation