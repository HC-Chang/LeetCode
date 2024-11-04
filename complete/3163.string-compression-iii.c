/*
 * @lc app=leetcode id=3163 lang=c
 *
 * [3163] String Compression III
 */

// @lc code=start
void convert_to_string(int *cnt, char *c, int *idx, char *s, int i,
                       char *word)
{
    while (*cnt > 9)
    {
        s[(*idx)++] = '9';
        s[(*idx)++] = *c;
        *cnt -= 9;
    }
    s[(*idx)++] = *cnt + '0';
    s[(*idx)++] = *c;
    *c = word[i];
    *cnt = 1;
}

char *compressedString(char *word)
{
    int n = strlen(word);
    char c = word[0];
    int cnt = 1;
    char *ans = malloc((2 * n + 1) * sizeof(char));
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (word[i] == c)
            cnt++;
        else
            convert_to_string(&cnt, &c, &idx, ans, i, word);
    }
    convert_to_string(&cnt, &c, &idx, ans, n - 1, word);
    ans[idx] = '\0';

    return ans;
}
// @lc code=end
