/*
 * @lc app=leetcode id=944 lang=c
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
int minDeletionSize(char **strs, int strsSize)
{
    int len = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (strs[0][j] == -1)
                continue;
            if (strs[i][j] - strs[i - 1][j] < 0)
                strs[0][j] = -1;
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (strs[0][i] == -1)
            count++;
    }
    return count;
}
// @lc code=end

// if not sorted: strs[0][i] = -1