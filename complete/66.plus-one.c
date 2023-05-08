/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int tmp = 1;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        digits[i] += tmp;
        tmp = 0;
        if (digits[i] <= 9)
            break;
        tmp = digits[i] / 10;
        digits[i] %= 10;
    }
    if (tmp != 0)
    {
        *returnSize = digitsSize + 1;
        int *new_arr = malloc((*returnSize) * sizeof(int));
        memcpy(new_arr + 1, digits, (*returnSize - 1) * sizeof(int));
        new_arr[0] = tmp;
        return new_arr;
    }
    *returnSize = digitsSize;
    return digits;
}
// @lc code=end
