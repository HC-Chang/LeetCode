/*
 * @lc app=leetcode id=1915 lang=c
 *
 * [1915] Number of Wonderful Substrings
 */

// @lc code=start
long long wonderfulSubstrings(char *word)
{
    long long total = 0;
    int nowMask = 0;
    int counts[1024] = {0};
    counts[0] = 1;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        nowMask ^= (1 << (word[i] - 'a'));
        total += counts[nowMask];
        for (int i = 0; i < 10; ++i)
            total += counts[nowMask ^ (1 << i)];
        ++counts[nowMask];
    }
    return total;
}
// @lc code=end

// Note: bit manipulation