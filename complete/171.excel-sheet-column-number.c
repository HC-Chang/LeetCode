/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
int titleToNumber(char *columnTitle)
{
    int sum = 0;
    int len = strlen(columnTitle);
    long long n = 1;
    while (len--)
    {
        sum += n * (columnTitle[len] - 'A' + 1);
        n *= 26;
    }
    return sum;
}
// @lc code=end
