/*
 * @lc app=leetcode id=796 lang=c
 *
 * [796] Rotate String
 */

// @lc code=start
bool rotateString(char *s, char *goal)
{
    int n = strlen(s);
    if (n != strlen(goal))
        return false;

    char tmp[n * n + 1];
    memcpy(tmp, s, n * sizeof(char));
    memcpy(tmp + n, s, n * sizeof(char));
    tmp[2 * n] = '\0';

    return strstr(tmp, goal);
}
// @lc code=end

// Note: string matching