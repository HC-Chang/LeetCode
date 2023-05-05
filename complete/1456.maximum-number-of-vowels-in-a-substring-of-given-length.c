/*
 * @lc app=leetcode id=1456 lang=c
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
int maxVowels(char *s, int k)
{
    int is_vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int s_len = strlen(s);
    int count = 0;
    for (int i = 0; i < k; i++)
        count += is_vowels[s[i] - 'a'];
    if (count == k)
        return k;

    int max_count = count;
    int left = 0;
    int right = k;
    while (right < s_len)
    {
        count += is_vowels[s[right++] - 'a'] - is_vowels[s[left++] - 'a'];
        if (count > max_count)
            max_count = count;
    }

    return max_count;
}
// @lc code=end
