/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start

void moveZeroes(int *nums, int numsSize)
{
    int index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (*(nums + i))
        {
            *(nums + index) = *(nums + i);
            index++;
        }
    }

    for (int i = index; i < numsSize; i++)
    {
        *(nums + i) = 0;
    }
}
// @lc code=end
