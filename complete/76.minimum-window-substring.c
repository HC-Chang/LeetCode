/*
 * @lc app=leetcode id=76 lang=c
 *
 * [76] Minimum Window Substring
 */

// @lc code=start

char *minWindow(char *s, char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);
    int left = 0;
    int right = 0;
    int s_valid_count = 0;
    int t_valid_count = 0;
    char *r;
    int start = 0;
    int r_len = INT_MAX;

    char c;

    //  A ~ z
    // 65 ~ 122
    int s_valids[58] = {0};
    int t_valids[58] = {0};

    for (int i = 0; i < t_len; i++)
    {
        t_valids[t[i] - 'A']++;
    }
    for (int i = 0; i < 58; i++)
    {
        if (t_valids[i] != 0)
        {
            t_valid_count++;
        }
    }

    while (right < s_len)
    {
        char c = s[right];
        right++;
        if (t_valids[c - 'A'])
        {
            s_valids[c - 'A']++;
            if (s_valids[c - 'A'] == t_valids[c - 'A'])
            {
                s_valid_count++;
            }
        }

        while (s_valid_count == t_valid_count)
        {
            if (right - left < r_len)
            {
                start = left;
                r_len = right - left;
                printf("%i %i\n", start, r_len);
            }
            char d = s[left];
            left++;
            if (t_valids[d - 'A'])
            {
                if (s_valids[d - 'A'] == t_valids[d - 'A'])
                {
                    s_valid_count--;
                }
                s_valids[d - 'A']--;
            }
        }
    }

    if (r_len == INT_MAX)
    {
        return "";
    }
    r = calloc(r_len + 1, sizeof(char));
    strncpy(r, s + start, r_len);
    return r;
}
// @lc code=end
