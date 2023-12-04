/*
 * @lc app=leetcode id=2264 lang=c
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
char *largestGoodInteger(char *num)
{
    char *ans = calloc(4, sizeof(char));
    int val = -1;
    int n = strlen(num);
    int count = 1;
    char c = num[0];
    int tmp;
    for (int i = 1; i < n; i++)
    {
        if (num[i] == c)
        {
            if (++count == 3)
            {
                tmp = num[i] - '0';
                if (val == -1 || tmp > val)
                    val = tmp;
            }
        }
        else
        {
            c = num[i];
            count = 1;
        }
    }
    if (val != -1)
    {
        for (int i = 0; i < 3; i++)
            ans[i] = val + '0';
    }

    return ans;
}
// @lc code=end
