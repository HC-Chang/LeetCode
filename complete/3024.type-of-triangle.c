/*
 * @lc app=leetcode id=3024 lang=c
 *
 * [3024] Type of Triangle
 */

// @lc code=start
int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

char *triangleType(int *nums, int numsSize)
{
    int cnt = 0;
    qsort(nums, numsSize, sizeof(int), sort);
    for (int i = 1; i < 3; i++)
    {
        if (nums[i] == nums[i - 1])
            cnt++;
    }
    if (nums[0] == nums[2])
        cnt++;
    if (cnt == 3)
        return "equilateral";
    else if (nums[0] + nums[1] <= nums[2])
        return "none";
    else if (cnt == 1)
        return "isosceles";

    return "scalene";
}
// @lc code=end

// Note: math + sorting