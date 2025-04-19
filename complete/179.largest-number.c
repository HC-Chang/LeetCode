/*
 * @lc app=leetcode id=179 lang=c
 *
 * [179] Largest Number
 */

// @lc code=start
int sort(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    unsigned long sx = 10, sy = 10;
    while (sx <= *x)
        sx *= 10;
    while (sy <= *y)
        sy *= 10;
    return sx * (*y) + (*x) - sy * (*x) - (*y);
}

char *largestNumber(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort);

    char *ans = calloc(1000, sizeof(char));
    for (int i = 0; i < numsSize; i++)
        sprintf(ans, "%s%i", ans, nums[i]);
    if (ans[0] == '0')
        return "0";
    return ans;
}
// @lc code=end

// Note: greedy + sorting