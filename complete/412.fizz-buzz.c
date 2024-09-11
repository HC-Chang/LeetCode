/*
 * @lc app=leetcode id=412 lang=c
 *
 * [412] Fizz Buzz
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    *returnSize = n;
    char **ans = malloc(n * sizeof(char *));
    int fizz = 3;
    int buzz = 5;
    for (int i = 0; i < n; i++)
    {
        ans[i] = calloc(9, sizeof(char));
        if (i + 1 == fizz && i + 1 == buzz)
        {
            ans[i] = "FizzBuzz";
            fizz += 3;
            buzz += 5;
        }
        else if (i + 1 == fizz)
        {
            ans[i] = "Fizz";
            fizz += 3;
        }
        else if (i + 1 == buzz)
        {
            ans[i] = "Buzz";
            buzz += 5;
        }
        else
            sprintf(ans[i], "%d", i + 1);
    }

    return ans;
}
// @lc code=end
