/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
char *convert(char *s, int numRows)
{
    int s_len = strlen(s);
    if (s_len <= numRows || numRows == 1)
        return s;

    int *group_index = calloc(s_len, sizeof(int));
    int trigger = 1;
    int index = 0;
    for (int i = 0; i < s_len; i++)
    {
        group_index[i] = index;
        index += trigger;

        if (index == 0 || index == numRows - 1)
            trigger *= -1;
    }

    char *r = calloc(s_len + 1, sizeof(char));
    index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < s_len; j++)
        {
            if (group_index[j] == i)
                r[index++] = s[j];
        }
    }

    free(group_index);
    return r;
}

// @lc code=end
