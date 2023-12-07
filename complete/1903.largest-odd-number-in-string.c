/*
 * @lc app=leetcode id=1903 lang=c
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
char *largestOddNumber(char *num)
{
    int n = strlen(num);
    char *ans = calloc(n + 1, sizeof(char));
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
        {
            strncpy(ans, num, i + 1);
            break;
        }
    }
    return ans;
}
// @lc code=end
