/*
 * @lc app=leetcode id=2176 lang=c
 *
 * [2176] Count Equal and Divisible Pairs in an Array
 */

// @lc code=start
int countPairs(int *nums, int numsSize, int k)
{
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j] && i * j % k == 0)
                ++cnt;
        }
    }
    return cnt;
}
// @lc code=end

// Note: array