/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

// @lc code=start
int missingNumber(int *nums, int numsSize)
{
    int hash[numsSize + 1];
    memset(hash, 0, (numsSize + 1) * sizeof(int));
    for (int i = 0; i < numsSize; i++)
        ++hash[nums[i]];
    int i;
    for (i = 0; i <= numsSize; i++)
    {
        if (hash[i] == 0)
            break;
    }
    return i;
}
// @lc code=end
