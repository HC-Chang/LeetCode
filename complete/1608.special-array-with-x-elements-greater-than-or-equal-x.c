/*
 * @lc app=leetcode id=1608 lang=c
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
int specialArray(int *nums, int numsSize)
{
    int cnt;
    for (int i = 0; i < numsSize + 1; i++)
    {
        cnt = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] >= i)
                cnt++;
        }
        if (cnt == i)
            return i;
    }

    return -1;
}
// @lc code=end
