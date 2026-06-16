/*
 * @lc app=leetcode id=3612 lang=c
 *
 * [3612] Process String with Special Operations I
 */

// @lc code=start
void reverse(char *s, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = tmp;
    }
}

void duplicate(char *s, int *n)
{
    for (int i = 0; i < *n; i++)
        s[(*n) + i] = s[i];
    *n = (*n) * 2;
}

char *processStr(char *s)
{
    char *ans = malloc(524289 * sizeof(char));
    int n = strlen(s);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case '#':
            duplicate(ans, &idx);
            break;
        case '%':
            reverse(ans, idx);
            break;
        case '*':
            if (idx)
                idx--;
            break;
        default:
            ans[idx++] = s[i];
            break;
        }
    }
    ans[idx] = '\0';

    return ans;
}
// @lc code=end
