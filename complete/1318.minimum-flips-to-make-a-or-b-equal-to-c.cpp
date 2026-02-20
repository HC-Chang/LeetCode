/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int cnt = 0;
        while (a > 0 || b > 0 || c > 0)
        {
            int aa = a & 1;
            int bb = b & 1;
            int cc = c & 1;
            if ((aa | bb) != cc)
            {
                if (cc != 1 && aa == bb)
                    cnt += 2;
                else
                    cnt++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};
// @lc code=end

// Note: Bit Manipulation