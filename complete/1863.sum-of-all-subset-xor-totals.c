/*
 * @lc app=leetcode id=1863 lang=c
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
// Solution 2: DFS
void dfs(int *r, int val, int index, int *nums, int numsSize)
{
    if (index == numsSize)
    {
        *r += val;
        return;
    }
    dfs(r, val ^ nums[index], index + 1, nums, numsSize);
    dfs(r, val, index + 1, nums, numsSize);
}

int subsetXORSum(int *nums, int numsSize)
{
    int r = 0;
    dfs(&r, 0, 0, nums, numsSize);
    return r;
}
// @lc code=end

// Solution 1:

// int subsetXORSum(int *nums, int numsSize)
// {
//     for (int i = 1; i < numsSize; i++)
//         nums[0] |= nums[i];
//     return nums[0] << numsSize - 1;
// }