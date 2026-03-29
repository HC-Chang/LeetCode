/*
 * @lc app=leetcode id=2839 lang=c
 *
 * [2839] Check if Strings Can be Made Equal With Operations I
 */

// @lc code=start
bool canBeEqual(char *s1, char *s2)
{
    int n = strlen(s1);
    if (strlen(s2) != n)
        return false;

    int used[n];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        else if (i + 2 < n && s1[i] == s2[i + 2])
            ++used[i];
        else if (i - 2 >= 0 && s1[i] == s2[i - 2])
            --used[i - 2];
        else
            return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i] != 0)
            return false;
    }

    return true;
}
// @lc code=end

// Note: string