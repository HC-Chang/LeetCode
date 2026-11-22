/*
 * @lc app=leetcode id=2124 lang=c
 *
 * [2124] Check if All A's Appears Before All B's
 */

// @lc code=start
bool checkString(char *s)
{
    bool check = false;
    while (*s)
    {
        if (*s == 'b')
            check = true;
        else if (check && *s == 'a')
            return false;
        s++;
    }
    return true;
}
// @lc code=end
