/*
 * @lc app=leetcode id=696 lang=c
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
int countBinarySubstrings(char *s)
{
    int ans = 0, previous = 0, current = 1;
    int n = strlen(s);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            current++;
        else
        {
            previous = current;
            current = 1;
        }
        if (current <= previous)
            ans++;
    }
    return ans;
}
// @lc code=end

// Note: two pointers