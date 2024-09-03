/*
 * @lc app=leetcode id=1945 lang=c
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
int getLucky(char *s, int k)
{
    int n = strlen(s);
    char *ss = malloc(3 * n * sizeof(char));
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            sprintf(ss + idx++, "%i", s[i] - 'a' + 1);
            if (s[i] - 'a' + 1 > 9)
                idx++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
            ss[idx++] = s[i];
    }

    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < idx; i++)
        tmp += ss[i] - '0';
    free(ss);

    ans = tmp;
    for (int i = 0; i < k - 1; i++)
    {
        tmp = 0;
        while (ans)
        {
            tmp += ans % 10;
            ans /= 10;
        }
        ans = tmp;
    }

    return ans;
}
// @lc code=end
