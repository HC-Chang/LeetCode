/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

// @lc code=start
int majorityElement(int *nums, int numsSize)
{
    int *map = calloc(100001, sizeof(int));
    int max_count = 1;
    int max_number = nums[0];
    map[nums[0] + 5000] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        map[nums[i] + 5000] += 1;
        if (map[nums[i] + 5000] > max_count)
        {
            max_count = map[nums[i] + 5000];
            max_number = nums[i];
        }
        if (max_count > (numsSize / 2 + 1))
        {
            free(map);
            return max_number;
        }
    }
    
    free(map);
    return max_number;
}
// @lc code=end
