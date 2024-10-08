/*
 * @lc app=leetcode id=1963 lang=c
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

// @lc code=start
int minSwaps(char *s)
{
    int stack_size = 0;
    int n = strlen(s);

    char ch;
    for (int i = 0; i < n; i++)
    {
        ch = s[i];
        if (ch == '[')
            stack_size++;
        else
        {
            if (stack_size > 0)
                stack_size--;
        }
    }
    return (stack_size + 1) / 2;
}
// @lc code=end

// Note: stack

// Official Solution