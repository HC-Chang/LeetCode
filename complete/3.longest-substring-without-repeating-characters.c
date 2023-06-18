/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
int lengthOfLongestSubstring(char *s)
{
    if (!s)
        return 0;

    int s_len = strlen(s);
    int max_count = 0;
    int *hash = calloc(95, sizeof(int));
    int left = 0;
    int right = 0;

    while (right < s_len)
    {
        if (hash[s[right] - 32] == 0)
            hash[s[right++] - 32] = 1;

        else if (hash[s[right] - 32] == 1)
            hash[s[left++] - 32] = 0;

        if (right - left > max_count)
            max_count = right - left;
    }

    free(hash);
    return max_count;
}

// @lc code=end
