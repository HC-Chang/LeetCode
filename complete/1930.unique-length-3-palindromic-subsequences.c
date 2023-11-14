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
    bool hash[26];
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        int l = 0, r = n - 1;

        while (l < n && s[l] != ch)
            ++l;

        while (r >= 0 && s[r] != ch)
            --r;

        if (r - l < 2)
            continue;

        memset(hash, 0, sizeof(hash));
        for (int k = l + 1; k < r; ++k)
        {
            if (hash[s[k] - 'a'] == false)
            {
                hash[s[k] - 'a'] = true;
                count++;
            }
        }
    }
    return count;
}
// @lc code=end

// Note: hash table