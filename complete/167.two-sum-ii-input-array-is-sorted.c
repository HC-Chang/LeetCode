/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 2;
    int left = 0;
    int right = numbersSize - 1;
    while (numbers[left] + numbers[right] != target)
    {
        if (numbers[left] + numbers[right] > target)
            right--;
        else
            left++;
    }

    numbers[0] = left + 1;
    numbers[1] = right + 1;
    return numbers;
}
// @lc code=end
