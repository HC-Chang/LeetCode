/*
 * @lc app=leetcode id=1497 lang=c
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
bool canArrange(int *arr, int arrSize, int k)
{
    int r[k];
    memset(r, 0, sizeof(r));

    int cnt;
    for (int i = 0; i < arrSize; i++)
    {
        cnt = arr[i] % k;
        if (cnt < 0)
            cnt += k;
        r[cnt]++;
    }

    if (r[0] % 2 != 0)
        return false;

    for (int i = 1; i <= k / 2; i++)
    {
        if ((r[i] != r[k - i]))
            return false;
    }

    return true;
}
// @lc code=end

// Note: hash table + counting