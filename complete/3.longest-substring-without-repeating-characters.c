/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#define max(a, b) a > b ? a : b

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
        {
            hash[s[right] - 32] = 1;
            right++;
        }
        else if (hash[s[right] - 32] == 1)
        {
            hash[s[left] - 32] = 0;
            left++;
        }

        max_count = max(max_count, right - left);
    }

    free(hash);
    return max_count;
}

// @lc code=end
