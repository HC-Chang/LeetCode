/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2;
    int *r = calloc(*returnSize, sizeof(int));
    int *map = calloc(10001, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {

        if (map[nums[i]] == 0)
            map[nums[i]] = 1;
        else
            r[0] = nums[i];
    }
    for (int i = 1; i < 10001; i++)
    {
        if (map[i] == 0)
        {
            r[1] = i;
            break;
        }
    }
    free(map);
    
    return r;
}
// @lc code=end
