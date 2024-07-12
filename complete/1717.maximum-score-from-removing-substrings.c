/*
 * @lc app=leetcode id=1717 lang=c
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap_char(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
int maximumGain(char *s, int x, int y)
{
    char c1 = 'a';
    char c2 = 'b';
    if (x < y)
    {
        swap_int(&x, &y);
        swap_char(&c1, &c2);
    }

    int ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c1)
            cnt1++;
        else if (s[i] == c2)
        {
            if (cnt1)
            {
                ans += x;
                cnt1--;
            }
            else
                cnt2++;
        }
        else
        {
            ans += fmin(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    ans += fmin(cnt1, cnt2) * y;
    return ans;
}
// @lc code=end

// Note: stack + greedy