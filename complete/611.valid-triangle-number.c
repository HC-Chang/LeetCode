/*
 * @lc app=leetcode id=611 lang=c
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
int binary_search(int i, int j, int *nums, int numsSize)
{
    int l = j + 1;
    int r = numsSize - 1;
    int target = nums[i] + nums[j];
    while (r >= l && r < numsSize)
    {
        int mid = (l + r) / 2;
        if (nums[mid] >= target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l - j - 1;
}

int sort(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int triangleNumber(int *nums, int numsSize)
{
    int cnt = 0;
    qsort(nums, numsSize, sizeof(int), sort);
    for (int i = 0; i < numsSize - 2; i++)
    {
        for (int j = i + 1; j < numsSize - 1; j++)
            cnt += binary_search(i, j, nums, numsSize);
    }
    return cnt;
}
// @lc code=end

// Note: sorting + binary search
