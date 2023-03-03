/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
int strStr(char *haystack, char *needle)
{
    int s_len = strlen(haystack);
    int n_len = strlen(needle);
    int index = 0;
    while (index + n_len <= s_len)
    {
        if (haystack[index] == needle[0])
        {
            if (!strncmp(&haystack[index], needle, n_len))
                return index;
        }
        index++;
    }
    return -1;
}
// @lc code=end