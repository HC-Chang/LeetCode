/*
 * @lc app=leetcode id=3223 lang=c
 *
 * [3223] Minimum Length of String After Operations
 */

// @lc code=start
int minimumLength(char *s)
{
    int hash[26] = {0};
    while (*s)
        ++hash[(*s++) - 'a'];

    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] == 0)
            continue;
        if (hash[i] % 2 == 0)
            cnt += 2;
        else
            cnt++;
    }
    return cnt;
}
// @lc code=end

// Note: hash table + counting