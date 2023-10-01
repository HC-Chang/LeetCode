/*
 * @lc app=leetcode id=2869 lang=c
 *
 * [2869] Minimum Operations to Collect Elements
 */

// @lc code=start
int minOperations(int *nums, int numsSize, int k)
{
    int visited[k];
    memset(visited, 0, (k) * sizeof(int));
    int idx = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (nums[i] <= k && visited[nums[i] - 1] == 0)
            visited[nums[i] - 1] = idx;
        idx++;
    }
    int min_op = visited[0];
    for (int i = 1; i < k; i++)
    {
        if (visited[i] > min_op)
            min_op = visited[i];
    }
    return min_op;
}
// @lc code=end
