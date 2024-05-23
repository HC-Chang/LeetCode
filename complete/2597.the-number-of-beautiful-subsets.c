/*
 * @lc app=leetcode id=2597 lang=c
 *
 * [2597] The Number of Beautiful Subsets
 */

// @lc code=start
int picked[1001];
int targets[20];

int dfs(int *numbers, int numsSize, int now)
{
    if (now == numsSize)
        return 1;
    if (picked[targets[now]])
        return dfs(numbers, numsSize, now + 1);
    ++picked[numbers[now]];
    int buffer = dfs(numbers, numsSize, now + 1);
    --picked[numbers[now]];
    return buffer + dfs(numbers, numsSize, now + 1);
}

int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int beautifulSubsets(int *nums, int numsSize, int k)
{

    qsort(nums, numsSize, sizeof(int), sort);
    for (int i = 0; i != numsSize; ++i)
        if (nums[i] > k)
            targets[i] = nums[i] - k;
        else
            targets[i] = 0;
    return dfs(nums, numsSize, 0) - 1;
}
// @lc code=end

// Note: DP + backtracking + sorting
