/*
 * @lc app=leetcode id=41 lang=c
 *
 * [41] First Missing Positive
 */

// @lc code=start
int firstMissingPositive(int *nums, int numsSize)
{
    int small = 1;
    int visited[numsSize + 2];
    memset(visited, 0, sizeof(visited));
    int tmp;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= small && nums[i] < numsSize + 1)
        {
            ++visited[nums[i]];
            if (nums[i] == small)
            {
                tmp = small;
                while (visited[tmp] > 0)
                    tmp++;
                small = tmp;
            }
        }
    }
    return small;
}
// @lc code=end

// Note: hash table