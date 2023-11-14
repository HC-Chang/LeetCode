/*
 * @lc app=leetcode id=1930 lang=c
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
int countPalindromicSubsequence(char *s)
{
    int n = strlen(s);
    int count = 0;
    int charset[26];
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        int l = 0, r = n - 1;

        while (l < n && s[l] != ch)
            ++l;

        while (r >= 0 && s[r] != ch)
            --r;

        if (r - l < 2)
            continue;

        memset(charset, 0, sizeof(charset));
        for (int k = l + 1; k < r; ++k)
        {
            ++charset[s[k] - 'a'];
            if (charset[s[k] - 'a'] == 1)
                count++;
        }
    }
    return count;
}
// @lc code=end

// Note: hash table