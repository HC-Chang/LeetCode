/*
 * @lc app=leetcode id=1347 lang=c
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */

// @lc code=start
int minSteps(char *s, char *t)
{
    int hash[26] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        ++hash[s[i] - 'a'];
        --hash[t[i] - 'a'];
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        cnt += abs(hash[i]);
    return cnt / 2;
}
// @lc code=end

// Note: hash table