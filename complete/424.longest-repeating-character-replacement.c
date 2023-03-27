/*
 * @lc app=leetcode id=424 lang=c
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
int max(int a, int b) { return a > b ? a : b; }
int max_val(int *arr, int arr_size)
{
    int r = arr[0];
    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] > r)
            r = arr[i];
    }
    return r;
}
int characterReplacement(char *s, int k)
{
    int *count = calloc(26, sizeof(int));

    int i = 0;
    int result = 0;
    int s_len = strlen(s);
    for (int j = 0; j < s_len; j++)
    {
        count[s[j] - 'A']++;

        while (j - i + 1 - max_val(count, 26) > k)
            count[s[i++] - 'A']--;

        result = max(result, j - i + 1);
    }
    return result;
}
// @lc code=end
