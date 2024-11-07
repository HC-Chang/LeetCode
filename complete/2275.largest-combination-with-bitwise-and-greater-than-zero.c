/*
 * @lc app=leetcode id=2275 lang=c
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
int largestCombination(int *candidates, int candidatesSize)
{
    int max_cnt = 0;
    int cnt = 0;
    for (int i = 0; i < 24; i++)
    {
        cnt = 0;
        for (int j = 0; j < candidatesSize; j++)
        {
            if ((candidates[j] & (1 << i)) != 0)
                cnt++;
        }
        max_cnt = fmax(max_cnt, cnt);
    }
    return max_cnt;
}
// @lc code=end

// Note: bit manipulation