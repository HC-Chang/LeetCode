/*
 * @lc app=leetcode id=2441 lang=c
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 */

// @lc code=start
int findMaxK(int *nums, int numsSize)
{
    int visited[2001] = {0};
    int ans = -1;
    for (int i = 0; i < numsSize; i++)
    {
        ++(visited[nums[i] + 1000]);
        if (visited[nums[i] + 1000] && visited[-nums[i] + 1000] && abs(nums[i]) > ans)
            ans = abs(nums[i]);
    }
    return ans;
}
// @lc code=end

// Note: hash table / sorting + two pointers