/*
 * @lc app=leetcode id=1903 lang=c
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
char *largestOddNumber(char *num)
{
    int n = strlen(num);
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
        {
            num[i + 1] = 0;
            return num;
        }
    }
    return "";
}
// @lc code=end
