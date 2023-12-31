/*
 * @lc app=leetcode id=1624 lang=c
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
int maxLengthBetweenEqualCharacters(char *s)
{
    int len = strlen(s);
    int hash[26];
    for (int i = 0; i < 26; i++)
        hash[i] = -1;
    int max = -1;
    int diff;
    for (int i = 0; i < len; i++)
    {
        if (hash[s[i] - 'a'] == -1)
            hash[s[i] - 'a'] = i;
        else
        {
            diff = i - hash[s[i] - 'a'] - 1;
            if (diff > max)
                max = diff;
        }
    }
    return max;
}
// @lc code=end

// Note: hash table