/*
 * @lc app=leetcode id=3461 lang=c
 *
 * [3461] Check If Digits Are Equal in String After Operations I
 */

// @lc code=start
bool hasSameDigits(char *s)
{
    int n = strlen(s);
    char tmp[n + 1];
    int idx = 0;
    while (n > 2)
    {
        memset(tmp, 0, sizeof(tmp));
        idx = 0;
        for (int i = 0; i < n - 1; i++)
            tmp[idx++] = ((s[i] - '0' + s[i + 1] - '0') % 10) + '0';
        strcpy(s, tmp);
        n = strlen(s);
    }
    if (n == 2 && s[0] == s[1])
        return true;
    return false;
}
// @lc code=end

// Note: simulation
