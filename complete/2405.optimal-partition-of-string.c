/*
 * @lc app=leetcode id=2405 lang=c
 *
 * [2405] Optimal Partition of String
 */

// @lc code=start
int partitionString(char *s)
{
    int r = 1;
    int v = 0;
    int s_len = strlen(s);
    int index;
    for (int i = 0; i < s_len; i++)
    {
        index = s[i] - 'a';
        if ((v >> index) & 1)
        {
            v = 0;
            ++r;
        }
        v |= 1 << index;
    }
    return r;
}
// @lc code=end
