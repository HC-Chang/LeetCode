/*
 * @lc app=leetcode id=2779 lang=c
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
int maximumBeauty(int *nums, int numsSize, int k)
{
    if (numsSize == 1)
        return 1;
    int max_val = 0;
    for (int i = 0; i < numsSize; i++)
        max_val = fmax(max_val, nums[i]);

    int n = max_val + 1;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] - k >= 0)
            ++arr[nums[i] - k];
        else
            ++arr[0];
        if (nums[i] + k + 1 <= max_val)
            --arr[nums[i] + k + 1];
    }

    int cnt = 0;
    int cur_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cur_sum += arr[i];
        cnt = fmax(cnt, cur_sum);
    }

    return cnt;
}
// @lc code=end

// Note: sorting + sliding window

// Official Solution