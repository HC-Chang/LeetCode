/*
 * @lc app=leetcode id=1759 lang=c
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
int countHomogenous(char *s)
{
    int s_len = strlen(s);
    long long sum = 1;
    int count = 1;
    for (int i = 1; i < s_len; i++)
    {
        if (s[i] == s[i - 1])
            ++count;
        else
            count = 1;
        sum += count;
    }

    return (int)(sum % (1000000007));
}
// @lc code=end
