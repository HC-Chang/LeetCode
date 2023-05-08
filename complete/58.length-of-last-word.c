/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start
int lengthOfLastWord(char *s)
{
    int count = 0;
    int start = 0;
    while (*s)
    {
        if (*s != ' ')
        {
            if (start == 0)
            {
                start = 1;
                count = 1;
            }
            else
                count++;
        }
        else
            start = 0;
        s++;
    }
    return count;
}
// @lc code=end
