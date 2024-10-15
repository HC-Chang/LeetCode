/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long swap_cnt = 0;
        int black_cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                swap_cnt += (long long)black_cnt;
            else
                black_cnt++;
        }

        return swap_cnt;
    }
};
// @lc code=end

// Note: greedy

// Official Solution