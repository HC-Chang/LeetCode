/*
 * @lc app=leetcode id=1239 lang=c
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
int maxLength(char **arr, int arrSize)
{
    int ans = 0;
    int masks[1 << arrSize];
    int masksSize = 0;
    masks[masksSize++] = 0;
    int mask;
    int len;
    char ch;
    for (int i = 0; i < arrSize; ++i)
    {
        len = strlen(arr[i]);
        mask = 0;
        for (int j = 0; j < len; ++j)
        {
            ch = arr[i][j] - 'a';
            if ((mask >> ch) & 1)
            {
                mask = 0;
                break;
            }
            mask |= 1 << ch;
        }
        if (mask == 0)
            continue;

        int m;
        for (int j = 0; j < masksSize; ++j)
        {
            m = masks[j];
            if ((m & mask) == 0)
            {
                masks[masksSize++] = m | mask;
                ans = fmax(ans, __builtin_popcount(m | mask));
            }
        }
    }
    return ans;
}
// @lc code=end

// Note: bit manipulation

// Official Solution