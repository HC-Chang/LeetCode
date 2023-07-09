/*
 * @lc app=leetcode id=2272 lang=c
 *
 * [2272] Substring With Largest Variance

 */

// @lc code=start
int largestVariance(char *s)
{
    int s_len = strlen(s);
    int ans = 0;
    for (char a = 'a'; a <= 'z'; ++a)
    {
        for (char b = 'a'; b <= 'z'; ++b)
        {
            if (a == b)
                continue;
            int f[2] = {0, -s_len};
            for (int i = 0; i < s_len; i++)
            {
                if (s[i] == a)
                {
                    f[0]++;
                    f[1]++;
                }
                else if (s[i] == b)
                {
                    f[1] = fmax(f[1] - 1, f[0] - 1);
                    f[0] = 0;
                }
                ans = fmax(ans, f[1]);
            }
        }
    }
    return ans;
}
// @lc code=end
