/*
 * @lc app=leetcode id=2169 lang=c
 *
 * [2169] Count Operations to Obtain Zero
 */

// @lc code=start
int countOperations(int num1, int num2)
{
    if (!num1 || !num2)
        return 0;

    if (num1 > num2)
        return 1 + countOperations(num1 - num2, num2);
    else
        return 1 + countOperations(num2 - num1, num1);
}
// @lc code=end

// Note: math + simulation