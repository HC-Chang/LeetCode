/*
 * @lc app=leetcode id=3042 lang=c
 *
 * [3042] Count Prefix and Suffix Pairs I
 */

// @lc code=start
int countPrefixSuffixPairs(char **words, int wordsSize)
{
    int cnt = 0;
    int n1, n2;
    char pre[50];
    char suf[50];
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = i + 1; j < wordsSize; j++)
        {
            n1 = strlen(words[i]);
            n2 = strlen(words[j]);
            if (n1 > n2)
                continue;
            memcpy(pre, words[j], n1);
            memcpy(suf, words[j] + (n2 - n1), n1);
            pre[n1] = 0;
            suf[n1] = 0;
            if (!strcmp(pre, words[i]) && !strcmp(suf, words[i]))
                cnt++;
        }
    }
    return cnt;
}
// @lc code=end

// Note: hash