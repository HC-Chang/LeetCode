/*
 * @lc app=leetcode id=402 lang=c
 *
 * [402] Remove K Digits
 */

// @lc code=start
char *removeKdigits(char *num, int k)
{
    int n = strlen(num);
    int keep = n - k;
    char *ans = malloc(n * sizeof(char));
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        while (k && idx && ans[idx - 1] > num[i])
        {
            idx--;
            --k;
        }
        if (idx || num[i] != '0')
            ans[idx++] = num[i];
    }
    while (idx && k--)
        idx--;
    ans[idx] = '\0';
    if (!strcmp(ans, ""))
        return "0";
    return ans;
}
// @lc code=end

// Note: stack