/*
 * @lc app=leetcode id=2109 lang=c
 *
 * [2109] Adding Spaces to a String
 */

// @lc code=start
char *addSpaces(char *s, int *spaces, int spacesSize)
{
    int n = strlen(s);
    char *ans = malloc((n + spacesSize + 1) * sizeof(char));
    int idx = 0;
    int s_idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s_idx < spacesSize && i == spaces[s_idx])
        {
            ans[idx++] = ' ';
            s_idx++;
        }
        ans[idx++] = s[i];
    }
    ans[n + spacesSize] = '\0';
    return ans;
}
// @lc code=end

// Note: two pointers