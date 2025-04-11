/*
 * @lc app=leetcode id=2843 lang=cpp
 *
 * [2843]   Count Symmetric Integers
 */

// @lc code=start
class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int cnt = 0;
        for (int a = low; a <= high; ++a)
        {
            if (a < 100 && a % 11 == 0)
                cnt++;
            else if (1000 <= a && a < 10000)
            {
                int l = a / 1000 + (a % 1000) / 100;
                int r = (a % 100) / 10 + a % 10;
                if (l == r)
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
