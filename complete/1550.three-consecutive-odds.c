/*
 * @lc app=leetcode id=1550 lang=c
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
bool threeConsecutiveOdds(int *arr, int arrSize)
{
    int cnt = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2)
        {
            if (++cnt == 3)
                return true;
        }
        else
            cnt = 0;
    }
    return false;
}
// @lc code=end

// Note: array