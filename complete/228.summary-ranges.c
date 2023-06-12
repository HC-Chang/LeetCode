/*
 * @lc app=leetcode id=228 lang=c
 *
 * [228] Summary Ranges
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
    char **arr = malloc(sizeof(char *));
    *returnSize = 0;
    int i = 0;
    int left, right;
    while (i < numsSize)
    {
        left = i;
        i++;
        while (i < numsSize && nums[i] == nums[i - 1] + 1)
            i++;

        right = i - 1;
        arr = realloc(arr, (*returnSize + 1)*sizeof(char*));
        arr[(*returnSize)] = malloc(25 * sizeof(char));
        if (right > left)
            sprintf(arr[(*returnSize)++], "%d->%d", nums[left], nums[right]);
        else
            sprintf(arr[(*returnSize)++], "%d", nums[left]);
    }
    return arr;
}
// @lc code=end
